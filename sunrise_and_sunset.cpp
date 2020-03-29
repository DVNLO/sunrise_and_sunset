#include <cmath>

double to_radians(double const angle_degrees)
{
    static double const A{ acos(-1.0) / 360 };
    return angle_degrees * A; 
}

double get_num_days_since_2000(double julian_date)
{
    return julian_date - 2'451'545.0 + 0.0008;
}

double get_mean_solar_noon(double const n, double const longitude_west)
{
    return n - longitude_west / 360;
}

double get_solar_mean_anomaly(double const mean_solar_noon)
{
    double D{ 357.5291 + 0.98560028 * mean_solar_noon };
    double q{ floor(D / 360) };
    double a{ q * 360 };
    return D - a;
}

double get_equation_of_center(double const solar_mean_anomaly)
{
    double const M{ to_radians(solar_mean_anomaly) }; 
    return 1.9148 * sin(M)
           + 0.0200 * sin(2 * M)
           + 0.0003 * sin(3 * M);
}

double get_ecliptic_longitude(double const solar_mean_anomaly, 
                              double const equation_of_center)
{
    double D{ solar_mean_anomaly 
              + equation_of_center
              + 180
              + 102.9372 };
    double q{ floor(D / 360) };
    double a{ q * 360 };
    return D - a;
}

double get_solar_transit(double const mean_solar_noon,
                         double const solar_mean_anomaly,
                         double const ecliptic_longitude)
{
    return 2'451'545.0 
           + mean_solar_noon
           + 0.0053 * sin(to_radians(solar_mean_anomaly))
           - 0.0069 * sin(2 * to_radians(ecliptic_longitude));
}

double get_declination_of_sun(double const ecliptic_longitude)
{
    static double const A{ sin(to_radians(23.44)) };
    return asin(sin(to_radians(ecliptic_longitude)) * A);
}

double get_hour_angle(double const latitude, 
                      double const declination_of_sun)
{
    static double const A{ sin(to_radians(-0.83)) };
    double const phi{ to_radians(latitude) };
    double const delta{ to_radians(declination_of_sun) };
    return acos((A - sin(phi) * sin(delta))
                 / (cos(phi) * cos(delta)));
}

double get_julian_date_sunrise(double const solar_transit,
                               double const hour_angle)
{
    return solar_transit - hour_angle / 360;
}

double get_julian_date_sunset(double const solar_transit,
                              double const hour_angle)
{
    return solar_transit + hour_angle / 360;
}

double get_sunrise()
{
    
}

double get_sunset()
{

}