#ifndef SUNRISE_SUNSET_JULIAN_DAY
#define SUNRISE_SUNSET_JULIAN_DAY
#include <cstdint>

int_fast32_t julian_day_number(int_fast16_t const year,
                               int_fast8_t const month,
                               int_fast8_t const day);
double julian_date(int_fast32_t julian_day_number,
                   int_fast8_t const hour,
                   int_fast8_t const minute,
                   int_fast8_t const second);
double julian_date(int_fast16_t const year,
                   int_fast8_t const month,
                   int_fast8_t const day,
                   int_fast8_t const hour, 
                   int_fast8_t const minute, 
                   int_fast8_t const second);

#endif  // SUNRISE_SUNSET_JULIAN_DAY
