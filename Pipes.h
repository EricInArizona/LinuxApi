// Written by Eric Chauvin 2022


// This is unfinished and will probably never be used since I
// am using sockets instead.
// See Sockets.h for more notes on that.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#pragma once



#include "BasicTypes.h"
#include "RangeC.h"


class Pipes
  {
  private:
  Int32 testForCopy = 123;
  char* writeBuf;
  char* readBuf;
  const Int32 arraySize = 1024 * 8;

  public:
  Pipes( void );
  Pipes( const Pipes& in );
  ~Pipes( void );
  bool makeNewPipe( const char* fullPathName,
                    const Int32 mode );
  Int32 openRead( const char* fullPathName );
  Int32 openWrite( const char* fullPathName );
  Int32 readPipe( Int32 fd, char* buf, Int32 count );

  };
