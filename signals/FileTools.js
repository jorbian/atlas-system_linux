#!/usr/bin/env node

const fs = require('fs');

class FileTools {

    static walkDirectory(
        dir=__dirname,
        isTargetItem=((x) => x === x),
        doThing=((x) => console.log(x))
    ) {
        const items = fs.readdirSync(
            dir, {withFileTypes: true}
        )
            .filter(isTargetItem);

        items.forEach((item) => doThing(item))
    }
}
