#include "julian_date.h"
#include <cmath>
#include <cassert>
#include <iostream>

constexpr double ABSOLUTE_ERROR_THRESHOLD{ 0.000'1 };

double absolute_error(double const lhs, double const rhs)
{
    return std::abs(lhs - rhs);
}

bool test_aavso_example(int_fast16_t const year,
                        int_fast8_t const month,
                        int_fast8_t const day,
                        int_fast8_t const hour, 
                        int_fast8_t const minute, 
                        int_fast8_t const second,
                        double const expected_jd)
{
    double actual_jd{ julian_date(year, 
                      month, 
                      day, 
                      hour, 
                      minute, 
                      second) };
    return absolute_error(actual_jd, 
                          expected_jd) < ABSOLUTE_ERROR_THRESHOLD;
}

bool test_aavso_example_1()
// Returns true if test passes otherwise returns false.
// https://www.aavso.org/computing-jd
{
    int_fast16_t year{ 2010 };
    int_fast8_t month{ 1 };
    int_fast8_t day{ 9 };
    int_fast8_t hour{ 23 };
    int_fast8_t minute{ 15 };
    int_fast8_t second{ 0 };
    int_fast32_t expected_jdn{ 2'455'206 };
    double expected_jd{ 2'455'206.468'8 };
    return test_aavso_example(year,
                              month,
                              day,
                              hour,
                              minute,
                              second,
                              expected_jd);
}

bool test_aavso_example_2()
// Returns true if test passes otherwise returns false.
// https://www.aavso.org/computing-jd
{
    int_fast16_t year{ 2010 };
    int_fast8_t month{ 2 };
    int_fast8_t day{ 14 };
    int_fast8_t hour{ 13 };
    int_fast8_t minute{ 21 };
    int_fast8_t second{ 0 };
    double expected_jd{ 2'455'242.056'3 };
    return test_aavso_example(year,
                              month,
                              day,
                              hour,
                              minute,
                              second,
                              expected_jd);
}

bool test_aavso_example_3()
// Returns true if actual and expected Julian Day Numbers (jdn) are equal.
// https://www.aavso.org/computing-jd
{
    int_fast16_t year{ 2010 };
    int_fast8_t month{ 1 };
    int_fast8_t day{ 28 };
    int_fast8_t hour{ 9 };
    int_fast8_t minute{ 25 };
    int_fast8_t second{ 0 };
    double expected_jd{ 2'455'224.892'4 };
    return test_aavso_example(year,
                              month,
                              day,
                              hour,
                              minute,
                              second,
                              expected_jd);
}

bool test_origin()
// Returns true if actual and expected Julian Day Numbers (jdn) are equal.
// Tests the origin of the Julian Day
{
    int_fast16_t year{ -4713 };
    int_fast8_t month{ 11 };
    int_fast8_t day{ 24 };
    int_fast8_t hour{ 12 };
    int_fast8_t minute{ 0 };
    int_fast8_t second{ 0 };
    double expected_jd{ 0.0 };
    return test_aavso_example(year,
                              month,
                              day,
                              hour,
                              minute,
                              second,
                              expected_jd);
}

int main()
{
    assert(test_aavso_example_1());
    assert(test_aavso_example_2());
    assert(test_aavso_example_3());
    assert(test_origin());
}