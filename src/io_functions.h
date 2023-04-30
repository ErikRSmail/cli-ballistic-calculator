#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS H

#include <stdio.h>

#include "calculations.h"
#include "structs.h"
#include "constants.h"
#include "enums.h"

void print_flight_data(struct ballistic_data *data, unsigned int step_size){
    printf("\n=== Flight Data ===\n\n");
    for(int i = 0; i < MAX_DISTANCE; i += step_size){
        printf("Distance (yards): %i    Velocity (ft/s): %.0f    Vertical Offset (inches): %.2f    Horizontal Offset (inches): %.2f    ToF (seconds): %.2f\n", i, data->flight_data[i].velocity, data->flight_data[i].vertical_offset, data->flight_data[i].horizontal_offset, data->flight_data[i].time_of_flight);
    }
}

void print_environmental_data(struct environmental_data *data){
    printf("\n=== Environmental Data ===\n");
    printf("\nWind Speed         ( mph ) : %.1f",data->wind_speed);
    printf("\nWind Angle     ( degrees ) : %.0f",data->wind_angle);
    printf("\nPressure          ( inHg ) : %.1f",data->pressure);
    printf("\nTemperature ( Fahrenheit ) : %.0f",data->temperature);
    printf("\nHumidity      ( relative ) : %.2f",data->humidity);
    printf("\nAltitude          ( feet ) : %.0f",data->altitude);
    printf("\n");
}

void print_system_data(struct system_data *data){
    printf("\n=== System Data ===\n");
    printf("\nDrag model                 : G%i",data->drag_model);
    printf("\nBC                         : %.3f",data->bc);
    printf("\nMuzzle Velocity   ( ft/s ) : %.0f",data->muzzle_velocity);
    printf("\nSight Height    ( inches ) : %.2f",data->sight_height);
    printf("\nShooting Angle ( degrees ) : %.0f",data->shooting_angle);
    printf("\nZero Distance    ( yards ) : %.0f",data->zero_distance);
    printf("\n");
}

void print_ballistic_data(struct ballistic_data *data, unsigned int step_size){
    print_system_data(&data->system_data);
    print_environmental_data(&data->environmental_data);
    print_flight_data(data, step_size);
}
#endif