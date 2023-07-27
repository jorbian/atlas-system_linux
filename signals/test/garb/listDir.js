#!/usr/bin/env node

const fs = require('fs');

function findSourceFiles(dir, name) {

    const filename = name
    const isSourceFile = (function () {
            const taskNum = filename.match(/^(\d+)/)[0];
            const fileExt = filename.slice(
                filename.lastIndexOf(".")
            );
            const pattern = new RegExp(`^${taskNum}-\\S+\\${fileExt}`);
                
            return ((x) => x.match(pattern));
    })();
    return (
        fs.readdirSync(dir)
            .filter(isSourceFile)
    );
}




console.log(findSourceFiles(".", "0-handle_signal.c"));