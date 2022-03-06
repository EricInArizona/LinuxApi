// Written by Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "BasicTypes.h"



// This is a wrapper for the C functions in stdio.h.


class StIO
  {
  private:

  public:
  static void cPuts( const char* toWrite );
  // static void printFD( Int32 d );
  // static void printFUD( Uint32 d );
  // static void putC( Uint16 c );

  };
