#include "julian_date.h"
#include <cassert>

bool test_aavso_example_1()
// Returns true if actual and expected Julian Day Numbers (jdn) are equal.
// https://www.aavso.org/computing-jd
{
    int_fast16_t year{ 2010 };
    int_fast8_t month{ 1 };
    int_fast8_t day{ 9 };
    int_fast32_t actual_jdn{ julian_day_number(year, month, day) };
    int_fast32_t expected_jdn{ 2'455'206 };
    return actual_jdn == expected_jdn;
}

bool test_aavso_example_2()
// Returns true if actual and expected Julian Day Numbers (jdn) are equal.
// https://www.aavso.org/computing-jd
{
    int_fast16_t year{ 2010 };
    int_fast8_t month{ 2 };
    int_fast8_t day{ 14 };
    int_fast32_t actual_jdn{ julian_day_number(year, month, day) };
    int_fast32_t expected_jdn{ 2'455'242 };
    return actual_jdn == expected_jdn;
}

bool test_aavso_example_3()
// Returns true if actual and expected Julian Day Numbers (jdn) are equal.
// https://www.aavso.org/computing-jd
{
    int_fast16_t year{ 2010 };
    int_fast8_t month{ 1 };
    int_fast8_t day{ 27 };
    int_fast32_t actual_jdn{ julian_day_number(year, month, day) };
    int_fast32_t expected_jdn{ 2'455'224 };
    return actual_jdn == expected_jdn;
}

int main()
{
    assert(test_aavso_example_1());
    assert(test_aavso_example_2());
    assert(test_aavso_example_3());
}