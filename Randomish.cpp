// Written by Eric Chauvin 2022
// This is licensed under the GNU General
// Public License (GPL), version 2.  It is the
// same license that Linux has.




#include "Randomish.h"
#include <random>
#include "Casting.h"



void Randomish::makeRandomBytes(
                            UTF16Buf& uBuf,
                            const Int32 howMany )
{
uBuf.clear();

std::random_device rd;

// rd.entropy()
// rd.min()
// rd.max()

// std::mersenne_twister_engine
// std::mt19937_64

std::mt19937 gen( rd() );

// Make a uniform distribution:
//std::uniform_int_distribution<> dist( 1,
//                               0xFFFFFFFF );

Int32 gotCount = 0;
for( Int32 count = 0; count < 100000; count++ )
  {
  // dist( gen())

  // Truncate the unsigned int to an 8 bit byte.
  UTF16 c = Casting::
                U64ToUTF16ByteTruncate( gen());
  if( c == 0 )
    continue;

  uBuf.appendVal( c );
  gotCount++;
  if( gotCount >= howMany )
    return;

  }
}
