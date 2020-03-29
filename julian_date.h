#ifndef SUNRISE_SUNSET_JULIAN_DATE
#define SUNRISE_SUNSET_JULIAN_DATE
#include <cstdint>

double get_julian_date(int_fast16_t const year,
                       int_fast8_t const month,
                       int_fast8_t const day,
                       int_fast8_t const hour, 
                       int_fast8_t const minute, 
                       int_fast8_t const second);

extern const double JULIAN_DATE_J2000;

#endif  // SUNRISE_SUNSET_JULIAN_DATE
