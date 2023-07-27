"use strict";
exports.__esModule = true;
exports.Task = void 0;
var fs = require('fs');
var path = require('path');
var subProcess = require('child_process');
var Task = (function () {
    function Task(filename) {
        this.taskFile = {
            dir: path.dirname(filename),
            bname: path.basename(filename, path.extname(filename)),
            ext: path.extname(filename)
        };
        this.sourceFiles = this.findSourceFiles();
        this.execCreated = false;
    }
    Task.prototype.findSourceFiles = function () {
        var bname = this.taskFile.bname;
        var ext = this.taskFile.ext;
        var isSourceFile = (function () {
            var _a, _b;
            var taskNum = (_b = (_a = (bname).match(/^(\d+)/)) === null || _a === void 0 ? void 0 : _a[0]) !== null && _b !== void 0 ? _b : "";
            var pattern = new RegExp("^".concat(taskNum, "-\\S+\\").concat(ext));
            return (function (x) { return x.match(pattern); });
        })();
        return (fs.readdirSync(this.taskFile.dir)
            .filter(isSourceFile));
    };
    Task.initalizeTest = function (filename) {
        var task;
        task = new Task(filename);
        return (task);
    };
    Task.prototype.createExecutable = function () {
        var executable = this.taskFile.bname;
        var srcFiles = (this.sourceFiles).join(" ");
        var compilationArgs = ("".concat(Task.flags, " ").concat(srcFiles, " -o ").concat(executable))
            .split(" ");
        var compilation = (subProcess.spawn(Task.compiler, compilationArgs));
        if (compilation.stderr) {
            compilation.stderr.on('data', function (data) {
                console.log("".concat(data));
            });
        }
        else {
            this.execCreated = true;
        }
    };
    Task.test = function (filename) {
        var currentTask = Task.initalizeTest(filename);
        currentTask.createExecutable();
        if (currentTask.execCreated) {
        }
    };
    Task.compiler = "gcc";
    Task.flags = "-Wall -Wextra -Werror -pedantic";
    return Task;
}());
exports.Task = Task;
//# sourceMappingURL=Task.js.map