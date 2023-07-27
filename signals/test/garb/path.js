const path = require('path');

var filename = "0-handle_signal.c"

var taskFile = {
    dir: path.dirname(filename),
    bname: path.basename(filename, path.extname(filename)),
    ext: path.extname(filename)
}

console.log(taskFile);