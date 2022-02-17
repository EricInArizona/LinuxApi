// Written by Eric Chauvin 2022
// This is licensed under the GNU General
// Public License (GPL), version 2.  It is the
// same license that Linux has.


#include "Threads.h"

#include <thread>
#include <chrono>


void Threads::sleep( Int32 milli )
{
std::this_thread::sleep_for(
                      std::chrono::milliseconds(
                      milli ));

}
