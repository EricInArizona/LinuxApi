// Written by Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Pipes.h"
#include "Casting.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>




Pipes::Pipes( void )
{
writeBuf = new char[Casting::i32ToU64( arraySize )];
readBuf = new char[Casting::i32ToU64( arraySize )];
}



Pipes::Pipes( const Pipes& in )
{
writeBuf = new char[Casting::i32ToU64( arraySize )];
readBuf = new char[Casting::i32ToU64( arraySize )];

// Make the compiler think the in value is
// being used.
if( in.testForCopy == 123 )
  return;

const char* showS = "The Pipes copy constructor"
         " should not be getting called.\n";

throw showS;
}



Pipes::~Pipes( void )
{
delete[] writeBuf;
delete[] readBuf;
}



bool Pipes::makeNewPipe( const char* fullPathName,
                         const Int32 mode )
{
// It is like creating a file, and it shows up with ls, but
// it's a named pipe.

// sys/stat.h
// extern int chmod (const char *__file, __mode_t __mode)
// extern int mkdir (const char *__path, __mode_t __mode)

// The mode that gets set is mode & ~umask.
// From the user's umask.


// 4   read permission
// 2   write permission
// 1   execute permission

// 0666 is octal.  3 bits for each digit, 0 through 7.
// 0666 is for read and write permissions for everybody.
// 0777 would be execute permission too.

Int32 result = mkfifo( fullPathName,
                       Casting::i32ToU32( mode ));
if( result == 0 )
  return true;

return false; // Result was -1.
}





Int32 Pipes::openRead( const char* fullPathName )
{
// O_CREAT, O_RDONLY, O_WRONLY, O_RDWR, O_APPEND,
// O_NONBLOCK, O_TRUNC

// A non-negative integer is the file handle.
// -1 is an error.

// If O_CREAT is not set and the file doesn't exist,
// then it will return -1.

// If O_NONBLOCK is set the named file is a fifo then
// it will return -1.

return open( fullPathName, O_RDONLY, 0666 );
}



Int32 Pipes::openWrite( const char* fullPathName )
{
return open( fullPathName, O_WRONLY, 0666 );
}


Int32 Pipes::readPipe( Int32 fd, char* buf, Int32 count )
{
// It can return 0 for end of file, or just nothing to read.
// Or it can return -1 for an error.
return Casting::i64ToI32(
          read( fd, buf, Casting::i32ToU64( count )));
}
