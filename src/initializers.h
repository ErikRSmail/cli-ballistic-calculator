#ifndef DEFAULTS_H
#define DEFAULTS_H

#include <stdlib.h>
#include <stdio.h>
#include "calculations.h"

//This example simulates a 147gr .308 out of a 20 inch barrel @STP with a 5mph crosswind. It only exists for demo/testing purposes
struct ballistic_data* default_init(){
    struct ballistic_data *input = (struct ballistic_data*)malloc(sizeof(struct ballistic_data));
        input->system_data.drag_model = G1;
        input->system_data.bc = 0.415;
        input->system_data.muzzle_velocity = 2804.0;
        input->system_data.sight_height = 1.58;
        input->system_data.shooting_angle = 0.0;
        input->system_data.zero_distance = 100;

        input->environmental_data.wind_speed = 5.0;
        input->environmental_data.wind_angle = 90.0;
        input->environmental_data.pressure = 29.53;
        input->environmental_data.temperature = 59.0;
        input->environmental_data.humidity = 0.58;
        input->environmental_data.altitude = 0.0;

        input->max_distance = 1000;

        input->flight_data = (struct flight_data*)malloc(sizeof(struct flight_data) * (input->max_distance + 1));
        calculate_ballistics(input);
    return input;
}

//prompts the user for ballistic parameters, computes a set of expected flight data, then returns the parameter + flight data to the user.
struct ballistic_data* cli_init(){
    struct ballistic_data *input = (struct ballistic_data*)malloc(sizeof(struct ballistic_data));
    input->system_data.drag_model;
    input->system_data.bc;
    input->system_data.muzzle_velocity;
    input->system_data.sight_height;
    input->system_data.shooting_angle;
    input->system_data.zero_distance;

    input->environmental_data.wind_speed;
    input->environmental_data.wind_angle;
    input->environmental_data.pressure;
    input->environmental_data.temperature;
    input->environmental_data.humidity;
    input->environmental_data.altitude;

    input->max_distance;
    printf("\nEnter Drag Model: G");
    scanf("%i",&input->system_data.drag_model);
    printf("\nEnter BC: ");
    scanf("%lf",&input->system_data.bc);
    printf("\nEnter Muzzle Velocity (ft/s): ");
    scanf("%lf",&input->system_data.muzzle_velocity);
    printf("\nEnter Sight Height (inches): ");
    scanf("%lf",&input->system_data.sight_height);
    printf("\nEnter Shooting Angle (degrees): ");
    scanf("%lf",&input->system_data.shooting_angle);
    printf("\nEnter Zero Distance (yards): ");
    scanf("%lf",&input->system_data.zero_distance);
    printf("\nEnter Wind Speed (mph): ");
    scanf("%lf",&input->environmental_data.wind_speed);
    printf("\nEnter Wind Angle (degrees): ");
    scanf("%lf",&input->environmental_data.wind_angle);
    printf("\nEnter Atmospheric Pressure (inHg): ");
    scanf("%lf",&input->environmental_data.pressure);
    printf("\nEnter Temperature (Farhrenheit): ");
    scanf("%lf",&input->environmental_data.temperature);
    printf("\nEnter Relative Humidity (decimal): ");
    scanf("%lf",&input->environmental_data.humidity);
    printf("\nEnter Altitude (feet): ");
    scanf("%lf",&input->environmental_data.altitude);
    printf("\nEnter Max Distance (yards): ");
    scanf("%i",&input->max_distance);

    input->flight_data = (struct flight_data*)malloc(sizeof(struct flight_data) * input->max_distance + 1);
    calculate_ballistics(input);

    return input;
}

#endif