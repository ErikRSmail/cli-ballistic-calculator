#ifndef STRUCTS_H
#define STRUCTS_H

#include "enums.h"
#include "constants.h"

struct system_data{
    enum drag_model drag_model;
    double bc;
    double muzzle_velocity; // in ft/s
    double sight_height;    // in inches
    double shooting_angle;  // in degrees. angle of elevation of sight
    double zero_distance;   // in yards
};

struct environmental_data{
    double wind_speed;      // in miles per hour
    double wind_angle;      // in degrees. 0 is a headwind. 90 is right to left
    double pressure;        // in inHg
    double temperature;     // in Fahrenheit
    double humidity;        // in relative humidity
    double altitude;        // in feet
};

struct flight_datum{
    double velocity;           // in ft/s
    double vertical_offset;    // in inches
    double horizontal_offset;  // in inches
    double time_of_flight;     // in seconds
};

struct ballistic_data{
    struct system_data system_data;
    struct environmental_data environmental_data;
    unsigned int max_distance;
    struct flight_datum flight_data[MAX_DISTANCE];
};

struct print_options{
    unsigned int print_system_data;
    unsigned int print_environmental_data;
    unsigned int print_flight_data;

    unsigned int print_horizontal_correction;
    unsigned int print_vertical_correction;

    unsigned int print_moa_correction;
    unsigned int print_mil_correction;
    unsigned int print_linear_correction;

    unsigned int print_velocity;
    unsigned int print_time_of_flight;

    unsigned int step_size;
    unsigned int max_distance;
};

#endif