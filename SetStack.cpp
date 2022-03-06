

#include "../LinuxApi/SetStack.h"
#include "../LinuxApi/Casting.h"

#include <sys/resource.h>



bool SetStack::setit( void )
{
const rlim_t kStackSize = 64L * 1024L * 1024L;   // min stack size = 64 Mb


// struct rlimit {
//           rlim_t rlim_cur;  // Soft limit
//           rlim_t rlim_max;  // Hard limit (ceiling for rlim_cur)
//           };

// On success, these system calls return 0.  On error, -1 is
// returned, and errno is set to indicate the error.


struct rlimit rl;

Int32 result = getrlimit( RLIMIT_STACK, &rl );
if( result != 0 )
  return false;

if( rl.rlim_cur < kStackSize )
  {
  rl.rlim_cur = kStackSize;
  result = setrlimit( RLIMIT_STACK, &rl );
  if (result != 0)
    return false;

  }

return true;
}





Int32 SetStack::getSize( void )
{

// struct rlimit {
//           rlim_t rlim_cur;  // Soft limit
//           rlim_t rlim_max;  // Hard limit (ceiling for rlim_cur)
//           };

// On success, these system calls return 0.  On error, -1 is
// returned, and errno is set to indicate the error.


struct rlimit rl;

Int32 result = getrlimit( RLIMIT_STACK, &rl );
if( result != 0 )
  return 0;

return Casting::U64ToI32( rl.rlim_cur );
}
