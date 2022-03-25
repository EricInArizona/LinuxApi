// Written by Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Threads.h"

#include <thread>
#include <chrono>


void Threads::sleep( Int32 milli )
{
std::this_thread::sleep_for(
                      std::chrono::milliseconds(
                      milli ));

}


