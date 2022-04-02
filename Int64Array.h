// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "RangeC.h"


class Int64Array
  {
  private:
  Int32 testForCopy = 123;
  Int32 arraySize = 0;
  Int32 lastAppend = 0;
  Int64* iArray;

  void increaseAppendSize( const Int32 howMuch );

  public:
  Int64Array( void );
  Int64Array( const Int64Array& obj );
  ~Int64Array( void );
  void setSize( const Int32 howBig );
  void appendVal( const Int64 toSet );

  inline Int32 getArraySize( void ) const
    {
    return arraySize;
    }


  inline Int32 getLastAppend( void ) const
    {
    return lastAppend;
    }

  inline void clearLastAppend( void )
    {
    lastAppend = 0;
    }

  inline Int64 getVal( const Int32 where ) const
    {
    // This might not be using lastAppend.
    // It might not be using appendVal().
    // So don't test here for that range.

    RangeC::test2( where, 0, arraySize - 1,
      "Int64Array.getVal arraySize range." );

    return iArray[where];
    }

  inline void setVal( const Int32 where,
                      const Int64 toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
           "Int64Array.setVal where range." );

    iArray[where] = toSet;
    }


  void copy( const Int64Array& in );

  };
