// Written by Eric Chauvin 2022
// This is licensed under the GNU General
// Public License (GPL), version 2.  It is the
// same license that Linux has.



#pragma once


#include "BasicTypes.h"
#include "RangeC.h"


class UTF16Buf
  {
  private:
  UTF16* cArray;
  Int32 arraySize = 0;
  Int32 last = 0;
  void increaseSize( const Int32 howMuch );

  public:
  UTF16Buf( void );
  UTF16Buf( const UTF16Buf &in );
  ~UTF16Buf( void );
  inline Int32 getLast( void ) const
    {
    return last;
    }

  inline void clear( void )
    {
    last = 0;
    }

  inline UTF16 valAt( const Int32 where ) const
    {
    RangeC::test( where, 0, arraySize - 1,
                  "UTF16Buf.valAt() range." );

    // It might not be using append().
    // RangeC::test( where, 0, last - 1,
      //       "UTF16Buf.valAt() past last." );

    return cArray[where];
    }

  void appendVal( const UTF16 toSet );

  };
