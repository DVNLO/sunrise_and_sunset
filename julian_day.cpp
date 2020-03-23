#include "julian_day.h"
#include <limits>

int_fast32_t julian_day_number(int_fast16_t const year,
                               int_fast8_t const month,
                               int_fast8_t const day)
/* Returns the Julian Day Number (JDN) for all Gregorian calendar dates
 * after November 23, −4713. Otherwise, returns -1. Assumes months January 
 * through December are enumerated from 1 to 12, respectively, and days 
 * are valid between 1 and 31, inclusive.
 * https://en.wikipedia.org/wiki/Julian_day#Converting_Gregorian_calendar_date_to_Julian_Day_Number
 */
{
    if(year < -4713 
       || month < 1 || month > 12 
       || day < 1 || day > 31)
    {
        return -1;
    }
    else
    {
        return (1461 * (year + 4800 + (month - 14)/12))/4
                + (367 * (month - 2 - 12 * ((month - 14)/12)))/12
                - (3 * ((year + 4900 + (month - 14)/12)/100))/4
                + day - 32075;
    }
}

double julian_date(int_fast32_t julian_day_number, 
                   int_fast8_t const hour, 
                   int_fast8_t const minute, 
                   int_fast8_t const second)
/* Returns the Julian Date given a Julian Day Number (JDN) and time of
 * day. Otherwise, returns infinity. Hours are from a 24-hour clock. 
 * https://en.wikipedia.org/wiki/Julian_day#Finding_Julian_date_given_Julian_day_number_and_time_of_day
 */
{
    if(julian_day_number < 0
       || hour < 0 || hour > 24
       || minute < 0 || minute > 60
       || second < 0 || second > 60)
    {
        return std::numeric_limits<double>::infinity();
    }
    else
    {
        if(hour < 12)
        {
            ++julian_day_number;
        }
        return julian_day_number
               + (static_cast<double>(hour) - 12)/24
               + static_cast<double>(minute)/1440
               + static_cast<double>(second)/86400;
    }
}

double julian_date(int_fast16_t const year,
                   int_fast8_t const month,
                   int_fast8_t const day,
                   int_fast8_t const hour, 
                   int_fast8_t const minute, 
                   int_fast8_t const second)
/* Returns the Julian Date given year, month, day, and time of day. Otherwise, 
 * returns infinity. Assumes months January through December are enumerated 
 * from 1 to 12, respectively. Days are valid between 1 and 31, inclusive. 
 * Hours are from a 24-hour clock. 
 * https://en.wikipedia.org/wiki/Julian_day
 */
{
    int_fast32_t jdn{ julian_day_number(year, 
                                        month, 
                                        day) };
    return julian_date(jdn,
                       hour,
                       minute,
                       second);
}