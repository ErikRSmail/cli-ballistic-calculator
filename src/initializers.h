#ifndef INITIALIZERS_H
#define INITIALIZERS_H

#include <stdlib.h>
#include <stdio.h>

#include "enums.h"
#include "calculations.h"
#include "constants.h"
#include "structs.h"

//This example simulates a 147gr .308 out of a 20 inch barrel @STP with a 5mph crosswind. It only exists for demo/testing purposes
struct ballistic_data* default_ballistic_data_init(){
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

        calculate_flight_data(input);
    return input;
}

struct ballistic_data* cli_ballistic_data_init(){
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

    calculate_flight_data(input);

    return input;
}

struct print_options* default_options(){
    struct print_options *options = (struct print_options*)malloc(sizeof(struct print_options));
        options->print_system_data = 1;
        options->print_environmental_data = 1;
        options->print_flight_data = 1;

        options->print_horizontal_correction = 1;
        options->print_vertical_correction = 1;

        options->print_moa_correction = 0;
        options->print_mil_correction = 1;
        options->print_linear_correction = 0;

        options->print_velocity = 1;
        options->print_time_of_flight = 1;

        options->step_size = 100;
        options->max_distance = 1000;

    return options;
}

struct print_options* cli_options_init(){
    struct print_options *options = (struct print_options*)malloc(sizeof(struct print_options));
        inline unsigned int yn_to_bool(char in){
            if(in == 'y'){
                return 1;
            }
            else if(in == 'n'){
                return 0;
            }
        }

        char in;
        printf("\nPrint System Data? (y/n) : ");
        scanf(" %c", &in);
        options->print_system_data = yn_to_bool(in);

        printf("\nPrint Environmental Data? (y/n) : ");
        scanf(" %c", &in);
        options->print_environmental_data = yn_to_bool(in);

        printf("\nPrint Flight Data? (y/n) : ");
        scanf(" %c", &in);
        options->print_flight_data = yn_to_bool(in);
        
        if(options->print_flight_data){
            printf("\nPrint Vertical Correction? (y/n) : ");
            scanf(" %c", &in);
            options->print_vertical_correction = yn_to_bool(in);
        
            printf("\nPrint Horizontal Correction? (y/n) : ");
            scanf(" %c", &in);
            options->print_horizontal_correction = yn_to_bool(in);
        
            printf("\nPrint Corrections in MOA? (y/n) : ");
            scanf(" %c", &in);
            options->print_moa_correction = yn_to_bool(in);
        
            printf("\nPrint Corrections in MIL? (y/n) : ");
            scanf(" %c", &in);
            options->print_mil_correction = yn_to_bool(in);
        
            printf("\nPrint Correction in Inches? (y/n) : ");
            scanf(" %c", &in);
            options->print_linear_correction = yn_to_bool(in);
        
            printf("\nPrint Velocity? (y/n) : ");
            scanf(" %c", &in);
            options->print_velocity = yn_to_bool(in);
        
            printf("\nPrint Time of Flight? (y/n) : ");
            scanf(" %c", &in);
            options->print_time_of_flight = yn_to_bool(in);
        
            printf("\nMax distance? (yards) : ");
            scanf(" %i", &options->max_distance);
            printf("\nPrinting interval? (yards) : ");
            scanf(" %i", &options->step_size);
        }

    return options;
}



#endif