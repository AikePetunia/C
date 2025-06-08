/*
How to compile in C: To compile a .c file, write in the terminal on the correct path:
$> gcc -Wall -Wextra -std=c99 myfile.c -o myprogram

To execute, write:
$> ./myprogram

To compile for gdb, add the -g flag when compiling the .c file, write in the terminal:
$> gcc -Wall -Wextra -std=c99 -g myfile.c -o myprogram

These flags mean:
-Wall: Enable all warnings
-Wextra: Enable extra warnings
-std=c99: Use C99 standard
-g: Include debugging information
-o myprogram: Specify output file name

debug:

gcc -Wall -Werror -Wextra -pedantic -std=c99 -g counter.o main.o -o counter
gdb ./counter
run input/balanced.in (if it need a inpout)
print
step

*/
