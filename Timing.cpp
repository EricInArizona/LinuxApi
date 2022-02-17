// Written by Eric Chauvin 2022
// This is licensed under the GNU General
// Public License (GPL), version 2.  It is the
// same license that Linux has.



#include "Timing.h"
#include "CharBuf.h"
#include <ctime>


Timing::Timing( void )
{
setNow();
}



void Timing::setNow( void )
{
time_t rawtime;

time( &rawtime );
timeSeconds = rawtime;

struct tm buf;
// errno_t errorNumber = localtime_s( &buf,
localtime_s( &buf, &rawtime );

// StIO::printFS( "Year:\n" );
// StIO::printFUD( 1900 + buf.tm_year );
// StIO::printFS( "\n" );

seconds = buf.tm_sec;
minutes = buf.tm_min;
hour = buf.tm_hour;
day = buf.tm_mday;
month = buf.tm_mon;
year = 1900 + buf.tm_year;
weekDay = buf.tm_wday; // Sunday = 0
yearDay = buf.tm_yday; // day of year to 365.
dayLightSavings = buf.tm_isdst;
}



Int64 Timing::diffSec( Timing& in )
{
return timeSeconds - in.timeSeconds;
}



Str Timing::timeStr( void )
{
CharBuf cBuf;


Str colon( ":" );
Str secS( seconds );
Str minS( minutes );
Str hourS( hour );

// Close enough for now.
cBuf.appendStr( hourS );
cBuf.appendStr( colon );
cBuf.appendStr( minS );
cBuf.appendStr( colon );
cBuf.appendStr( secS );

return cBuf.getStr();
}
