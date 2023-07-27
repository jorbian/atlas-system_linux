import { ChildProcess } from "child_process";

const fs = require('fs');
const path = require('path');
const subProcess = require('child_process');

export class Task {
    private static readonly compiler: string = "gcc";
    private static readonly flags: string = "-Wall -Wextra -Werror -pedantic";

    private taskFile: {
        dir: string,
        bname: string,
        ext: string
    };
    private sourceFiles: string[];
    private execCreated: boolean;
    private testRun: boolean;

    public constructor(filename: string) {
        this.taskFile = {
            dir: path.dirname(filename),
            bname: path.basename(filename, path.extname(filename)),
            ext: path.extname(filename)
        };
        this.sourceFiles = this.findSourceFiles();
        this.execCreated = false;
    }

    private findSourceFiles() {
        const bname: string = this.taskFile.bname;
        const ext: string = this.taskFile.ext;
        const isSourceFile = (function () {
                const taskNum: string = (bname).match(/^(\d+)/)?.[0] ?? "";
                const pattern: RegExp = new RegExp(`^${taskNum}-\\S+\\${ext}`);
                    
                return ((x: string) => x.match(pattern));
        })();
        return (
            fs.readdirSync(this.taskFile.dir)
                .filter(isSourceFile)
        );
    }

    private static initalizeTest(filename: string): Task {
        let task: Task;

        task = new Task(filename)

        return (task)
    }

    private createExecutable(): void {
        const executable: string = this.taskFile.bname;
        const srcFiles: string = (this.sourceFiles).join(" ");
        const compilationArgs: string[] = (`${Task.flags} ${srcFiles} -o ${executable}`)
            .split(" ");
        const compilation: ChildProcess = (
            subProcess.spawn(
                Task.compiler,
                compilationArgs,
            )
        );
        if (compilation.stderr) {
            compilation.stderr.on('data', (data) => {
                console.log(`${data}`);
            });
        }
        else {
            this.execCreated = true;
        }
    }

    public static test(filename: string) {
        let currentTask: Task = Task.initalizeTest(filename);

        currentTask.createExecutable();

        if (currentTask.execCreated) {

        }
    }
}
