#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "julian_date.h"

void usage()
{
    puts("This application returns the sunrise or sunset time when provided"
         " year, month, day, hour, minute, second, and longitude. Provide" 
         " these arguments in the following format:\n"
         " sunrise_and_sunset YYYY MM DD HH MM SS L\n"
         "Where YYYY is the year, MM is the month, DD is the day, HH is the"
         " hour, MM is the minute, SS is the second, and L is the longitude"
         " of the location where sunrise and sunset times are being requested."
         " The longitudinal argument should be provided as a real number"
         " (eg: 3.14) containing no more than 38 digits. Eastward longitudes"
         " are considered positive; west negative.");
}

int main(int const argc, char const * const argv[])
{
    int constexpr REQUIRED_ARG_COUNT{ 8 };
    int_fast8_t constexpr IDX_YEAR{ 1 };
    int_fast8_t constexpr IDX_MONTH{ 2 };
    int_fast8_t constexpr IDX_DAY{ 3 };
    int_fast8_t constexpr IDX_HOUR{ 4 };
    int_fast8_t constexpr IDX_MINUTE{ 5 };
    int_fast8_t constexpr IDX_SECOND{ 6 };
    int_fast8_t constexpr IDX_LONGITUDE{ 7 };
    if(argc != REQUIRED_ARG_COUNT)
    {
        usage();
        return EXIT_FAILURE;
    }
    int_fast16_t year{ static_cast<int_fast16_t>(atoi(argv[IDX_YEAR])) };
    int_fast8_t month{ static_cast<int_fast8_t>(atoi(argv[IDX_MONTH])) };
    int_fast8_t day{ static_cast<int_fast8_t>(atoi(argv[IDX_DAY])) };
    int_fast8_t hour{ static_cast<int_fast8_t>(atoi(argv[IDX_HOUR])) };
    int_fast8_t minute{ static_cast<int_fast8_t>(atoi(argv[IDX_MINUTE])) };
    int_fast8_t second{ static_cast<int_fast8_t>(atoi(argv[IDX_SECOND])) };
    double longitude{ static_cast<double>(atoi(argv[IDX_LONGITUDE])) };
    double julian_date{ get_julian_date(year, 
                                        month,
                                        day,
                                        hour,
                                        minute,
                                        second) };
}