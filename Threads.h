// Written by Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "BasicTypes.h"


class Threads
  {
  private:

  public:
  static void sleep( Int32 milli );

  };





/*
I don't think I will ever be using threads like this:


#include <thread>  

  std::thread first (foo); 
  std::thread second (bar,0);


*/


