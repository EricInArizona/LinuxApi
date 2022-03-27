// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



// I decided to use sockets for almost all interprocess
// communication.  For one thing I can run processes on
// one local machine or on multiple machines, and I'd
// have to make very few changes in the programs.
// I could test something on my local machine, but then
// run several Amazon EC2 instances for different processes.
// I can't do that with pipes.


#pragma once



#include "BasicTypes.h"
#include "RangeC.h"


class Sockets
  {
  private:
  Int32 testForCopy = 123;
  char* writeBuf;
  char* readBuf;
  const Int32 arraySize = 1024 * 8;

  public:
  Sockets( void );
  Sockets( const Sockets& in );
  ~Sockets( void );


  };
