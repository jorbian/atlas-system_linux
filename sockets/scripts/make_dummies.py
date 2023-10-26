#!/usr/bin/python3

from pathlib import Path

TEMPLATE_NAME = "task4.c"
LIBNAME = "socketlib"
RULE_TEMPLATE = "EXEC: SRC.o LIB.o\n\t$(CC) $(CFLAGS) -o EXEC SRC.o LIB.o\n\nSRC.o: SRC.c LIB.h\n\t$(CC) $(CFLAGS) -c SRC.c"
LIBRULE = ("NAME.o: NAME.c NAME.h\n\t$(CC) $(CFLAGS) -c NAME.c").replace("NAME", "socketlib")
EXECUTABLE_NAMES = [f'todo_api_{x}' for x in range(0, 6)]

makefile = "CC = gcc\nCFLAGS = -Wall -Werror -Wextra -pedantic\n"

project_folder = Path(".")
project_files = project_folder.glob("*")

template_obj = next((x for x in project_files if TEMPLATE_NAME in x.name), Path())
template_code = template_obj.read_text()

start_num = int(template_obj.stem[-1])
src_names = (
    f'{template_obj.stem[:-1]}{str(x)}'
        for x in range(start_num, start_num + 6)
)
task_data = dict(zip(src_names, EXECUTABLE_NAMES))

for (src, exec) in task_data.items():
    rule = (
        ((RULE_TEMPLATE
            .replace("SRC", src))
            .replace("EXEC", exec))
            .replace("LIB", LIBNAME)
        )
    makefile += f"\n{rule}\n"
    Path(f'{src}.c').write_text(template_code)

Path(f'Makefile').write_text(makefile)
