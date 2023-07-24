class ExampleFile {
    // This needs to be an all or nothing deal --
    static #isInternalConstructing = false;

    static targetClassName = "task-card";
    static selectExampleText = "pre > code";
    static findSourceFile = /(?!(.*?)\$)(.*(?:\r?\n))([\s\S]*?)(?=^.*?\$\s|\Z)/m;
    static currentProjectDir = 'documents';

    constructor(name, contents) {
        if (!ExampleFile.#isInternalConstructing) {
          throw new TypeError("ExampleFile is not constructable.");
        }
        ExampleFile.#isInternalConstructing = false;
        
        this.name = name;
        this.contents = contents;
    }

    static #extractFileName(lineWithName) {
        const findFileName = /(?<=cat )(.*)/; //This will only work 85-90% of the time!!
        const searchResults = lineWithName.match(findFileName);
    
        if (searchResults) {
            return searchResults[0];
        }
        else {
            return "";
        }
    }

    #findFileExtension() {
        const filename = this.name;
        return filename.substring(filename.indexOf('.')).trim();
    }

    static scrapeAllExampleFiles() {
        const exampleFiles = [];
    
        $(`.${ExampleFile.targetClassName}`).each(function() {
            const example = $(this).find(ExampleFile.selectExampleText)[0];
            if (example) {
                const rawData = example.textContent;
                const searchResults = rawData.match(ExampleFile.findSourceFile);
                const containsFile = searchResults[0].includes("cat");

                if (containsFile) {
                    ExampleFile.#isInternalConstructing = true;
                    exampleFiles.push(new ExampleFile(
                            ExampleFile.#extractFileName(searchResults[2]),
                            searchResults[3]
                        )
                    );
                }
            }
        });   
        return exampleFiles;
    }

    async #getFileHandle() {
        const options = {
          suggestedName: this.name,
          types: [
            {
              description: 'Example Files',
              accept: {
                'text/plain': [this.#findFileExtension()],
              },
            },
          ],
        };
      
        // prompt the user for the location to save the file.
        const handle = await window.showSaveFilePicker(options);
      
        return handle
      }
      
      async saveExample() {
        const handle = await this.#getFileHandle();
        const writable = await handle.createWritable();
      
        await writable.write(
            new Blob(
                [this.contents],
                {type: "text/plain"}
            )
        );
        await writable.close();
      }
    }

let examples = ExampleFile.scrapeAllExampleFiles();

examples.forEach(async function(file) {
    await file.saveExample();
});