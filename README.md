# LinuxApi

The Linux API Project

This is not a complete set of functions for
the Linux API, it's just things that I have
needed so far.

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


