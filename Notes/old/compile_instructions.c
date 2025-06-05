/*
C COMPILATION AND DEBUGGING GUIDE
=================================

BASIC COMPILATION:
-----------------
To compile a C file, use gcc with appropriate warning flags:
$> gcc -Wall -Wextra -std=c99 miarchivo.c -o miprograma

Where:
- gcc: GNU C Compiler
- -Wall: Enable all common warnings
- -Wextra: Enable extra warnings not covered by -Wall
- -std=c99: Use C99 standard (alternatives: -std=c89, -std=c11, -std=c17)
- miarchivo.c: Source file
- -o miprograma: Output executable name

EXECUTION:
---------
To run the compiled program:
$> ./miprograma

DEBUGGING WITH GDB:
-----------------
1. Compile with debugging symbols:
   $> gcc -Wall -Wextra -std=c99 -g miarchivo.c -o miprograma

   The -g flag adds debugging information to the executable.

2. Start the debugger:
   $> gdb ./miprograma

3. Common GDB commands:
   - run (or r): Start program execution
   - break (or b) line_number: Set breakpoint at specified line
   - break function_name: Set breakpoint at function
   - continue (or c): Continue execution after breakpoint
   - next (or n): Execute next line (step over functions)
   - step (or s): Execute next line (step into functions)
   - print variable_name: Show variable value
   - watch variable_name: Watch for changes in variable
   - backtrace (or bt): Show call stack
   - info locals: Show local variables
   - quit (or q): Exit GDB

4. Conditional breakpoints:
   $> break line_number if condition
   Example: break 25 if x == 10

5. Examining memory:
   $> x/nfu address
   Where:
   - n: Number of units to display
   - f: Format (d-decimal, x-hex, s-string)
   - u: Unit size (b-byte, h-halfword, w-word)

ADDITIONAL COMPILATION OPTIONS:
-----------------------------
- -O0, -O1, -O2, -O3: Optimization levels (0=none, 3=maximum)
- -Werror: Treat all warnings as errors
- -pedantic: Issue warnings for uses that don't follow ISO C
- -fPIC: Generate position-independent code (for shared libraries)
- -D NAME=value: Define preprocessor macro
- -I directory: Add directory to include search path
- -pthread: Add support for multithreading
- -m32/-m64: Generate 32-bit/64-bit code

USING VALGRIND FOR MEMORY CHECKING:
---------------------------------
$> valgrind --leak-check=full ./miprograma

USING SANITIZERS:
---------------
$> gcc -Wall -Wextra -std=c99 -fsanitize=address -g miarchivo.c -o miprograma
This enables the AddressSanitizer to detect memory errors
*/