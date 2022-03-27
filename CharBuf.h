// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#pragma once



#include "BasicTypes.h"
#include "Str.h"
#include "RangeC.h"


class CharBuf
  {
  private:
  Int32 testForCopy = 123;
  char* cArray;
  Int32 arraySize = 0;
  Int32 last = 0;
  void increaseSize( Int32 howMuch );

  public:
  CharBuf( void );
  CharBuf( const CharBuf &in );
  ~CharBuf( void );

  inline Int32 getLast( void ) const
    {
    return last;
    }

  inline void clear( void )
    {
    last = 0;
    }

  // This is used with getLast() like in
  // FileIO.writeAll() to pass the right size
  // of the buffer being pointed to.
  const char* getBufPoint( void ) const
    {
    return cArray;
    }

  void appendChar( const char toSet );
  void appendChars( const char* pStr );
  void appendCharBuf( const char* buf,
                      const Int32 howMany );

  void appendStr( const Str& in );
  Str getStr( void ) const;
  inline char valAt( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharBuf.valAt() arraySize." );

    RangeC::test2( where, 0, last - 1,
             "CharBuf.valAt() last." );

    return cArray[where];
    }

  };
