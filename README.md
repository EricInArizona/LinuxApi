# LinuxApi

The Linux API Project

This is not a complete set of functions for
the Linux API, it's just things that I have
needed so far.  It is things from the C Standard
Library like file I/O, so some of these work on
both Windows and Linux.  But it is also for things
like the Direct Rendering Manager on Linux,
(especially GPGPU to do computation on the GPU).
Or they are even more basic than that, like a
buffer for char or int values.

Check the whole BasicTypes.h file to make sure
it is right for your system.

I never use the C preprocessor except to use
#include statements.

Standard system #include files like <stdio.h> are
never put in these LinuxApi header files.  They
are only put in the .cpp files, so you can include
any of these header files without polluting your
files with a lot of macro definitions or other
things.

My Crypto project uses these.

When you use the #include statement, use what
ever path is relevant to your system.  What ever
works for where you put the files.

Examples:
On Linux:
#include "../LinuxApi/BasicTypes.h"
On Windows:
#include "..\\LinuxApi\\BasicTypes.h"
Or maybe even:
#include <BasicTypes.h>

I just compile this along with my project
similar to this:

cd YourDir
clang++ *.cpp \LinuxApi\*.cpp -o main.exe -L\LinuxApi

