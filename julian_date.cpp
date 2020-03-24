#include "julian_date.h"
#include <limits>

double julian_date(int_fast16_t const year,
                   int_fast8_t const month,
                   int_fast8_t const day,
                   int_fast8_t const hour, 
                   int_fast8_t const minute, 
                   int_fast8_t const second)
/* Returns the Julian Date given year, month, day, and time of day for all
 * Gregorian calendar dates after November 23, −4713. Otherwise, returns 
 * infinity. Assumes months January through December are enumerated 
 * from 1 to 12, respectively. Days enumerated between 1 and 31, inclusive. 
 * Hours are from a 24-hour clock in Universal Time (UT). 
 * https://en.wikipedia.org/wiki/Julian_day
 */
{
    if(year < -4713 
       || month < 1 || month > 12 
       || day < 1 || day > 31
       || hour < 0 || hour > 24
       || minute < 0 || minute > 60
       || second < 0 || second > 60)
    {
        return std::numeric_limits<double>::infinity(); 
    }
    int_fast32_t jdn{ (1461 * (year + 4800 + (month - 14)/12))/4
                       + (367 * (month - 2 - 12 * ((month - 14)/12)))/12
                       - (3 * ((year + 4900 + (month - 14)/12)/100))/4
                       + day - 32075 };
    double jd{ static_cast<double>(jdn)
               + (static_cast<double>(hour) - 12)/24
               + static_cast<double>(minute)/1440
               + static_cast<double>(second)/86400 };
    return jd;
}