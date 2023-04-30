#ifndef INITIALIZERS_H
#define INITIALIZERS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "calculations.h"
#include "constants.h"

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
        input->environmental_data.pressure = STANDARD_PRESSURE;
        input->environmental_data.temperature = STANDARD_TEMPERATURE;
        input->environmental_data.humidity = STANDARD_HUMIDITY;
        input->environmental_data.altitude = 0.0;

        input->max_distance = 1001;

        input->flight_data = (struct flight_datum*)malloc(sizeof(struct flight_datum) * input->max_distance);
        calculate_flight_data(input);
    return input;
}

struct ballistic_data* cli_init(){
    struct ballistic_data *input = (struct ballistic_data*)malloc(sizeof(struct ballistic_data));

    printf("\nEnter Drag Model              ( G1 or G7 ): G");
    scanf("%i",&input->system_data.drag_model);
    printf("\nEnter BC                         ( > 0.0 ): ");
    scanf("%lf",&input->system_data.bc);
    printf("\nEnter Muzzle Velocity ( feet per second ) : ");
    scanf("%lf",&input->system_data.muzzle_velocity);
    printf("\nEnter Sight Height             ( inches ) : ");
    scanf("%lf",&input->system_data.sight_height);
    printf("\nEnter Shooting Angle          ( degrees ) : ");
    scanf("%lf",&input->system_data.shooting_angle);
    printf("\nEnter Zero Distance             ( yards ) : ");
    scanf("%lf",&input->system_data.zero_distance);
    printf("\nEnter Wind Speed       ( miles per hour ) : ");
    scanf("%lf",&input->environmental_data.wind_speed);
    printf("\nEnter Wind Angle              ( degrees ) : ");
    scanf("%lf",&input->environmental_data.wind_angle);
    printf("\nEnter Atmospheric Pressure       ( inHg ) : ");
    scanf("%lf",&input->environmental_data.pressure);
    printf("\nEnter Temperature          ( Fahrenheit ) : ");
    scanf("%lf",&input->environmental_data.temperature);
    printf("\nEnter Relative Humidity    ( 0.0 to 1.0 ) : ");
    scanf("%lf",&input->environmental_data.humidity);
    printf("\nEnter Altitude                   ( feet ) : ");
    scanf("%lf",&input->environmental_data.altitude);
    printf("\nEnter Max Distance              ( yards ) : ");
    scanf("%i",&input->max_distance);
    input->max_distance++;

    input->flight_data = (struct flight_datum*)malloc(sizeof(struct flight_datum) * input->max_distance);
    calculate_flight_data(input);

    return input;
}

#endif