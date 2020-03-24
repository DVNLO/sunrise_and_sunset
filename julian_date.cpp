#include "julian_date.h"
#include <limits>

inline bool is_leap_year(int_fast32_t const year)
// https://stackoverflow.com/a/11595914
{
    return ((year & 3) == 0 
            && ((year % 25) != 0 
                || (year & 15) == 0));
}

int_fast8_t days_in_month(int_fast16_t const year,
                          int_fast8_t const month)
{
    static int_fast8_t constexpr JANUARY{ 1 };
    static int_fast8_t constexpr FEBRUARY{ 2 };
    static int_fast8_t constexpr MARCH{ 3 };
    static int_fast8_t constexpr APRIL{ 4 };
    static int_fast8_t constexpr MAY{ 5 };
    static int_fast8_t constexpr JUNE{ 6 };
    static int_fast8_t constexpr JULY{ 7 };
    static int_fast8_t constexpr AUGUST{ 8 };
    static int_fast8_t constexpr SEPTEMBER{ 9 };
    static int_fast8_t constexpr OCTOBER{ 10 };
    static int_fast8_t constexpr NOVEMBER{ 11 };
    static int_fast8_t constexpr DECEMBER{ 12 };
    switch(month)
    {
    case JANUARY : case MARCH : case MAY : 
    case JULY : case AUGUST : case OCTOBER :
    case DECEMBER :
        return 31;
    case APRIL : case JUNE : case SEPTEMBER :
    case NOVEMBER :
        return 30;
    case FEBRUARY:
    {
        if(is_leap_year(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    default:
        return -1;
    }
}

inline bool is_valid_gregorian_date(int_fast16_t const year, 
                                    int_fast8_t const month, 
                                    int_fast8_t const day)
{
    return month >= 0  && month <= 12 
            && day >= 0 && day <= days_in_month(year, month);
}

inline bool is_valid_24_hour_time(int_fast8_t const hour, 
                                  int_fast8_t const minute, 
                                  int_fast8_t const second)
{
    return hour >= 0 && hour <= 24
            && minute >= 0 && minute <= 60
            && second >= 0 && second <= 60;
}

inline bool can_map_to_julian_date(int_fast16_t const year, 
                                   int_fast8_t const month, 
                                   int_fast8_t const day)
/* Returns true if the provided Gregorian calendar year, month, and day
 * can map to a Julian Date. Otherwise returns false. All Gregorian 
 * calendar dates after November 23, −4713 can map to a Julian Date.
 * Assumes a valid gregorian date is provided.
 */
{
    return year > -4713 
            || year == -4713 && (month >= 11 || (month == 11 && day > 23));
}

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
    if(!is_valid_gregorian_date(year, month, day)
       || !is_valid_24_hour_time(hour, minute, second)
       || !can_map_to_julian_date(year, month, day))
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