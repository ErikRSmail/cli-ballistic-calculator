#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS H

#include <stdio.h>

#include "calculations.h"

void print_flight_data(struct ballistic_data *data, unsigned int step_size){
    for(int i = 0; i <= data->max_distance; i += step_size){
        printf("Distance (yards): %i    Velocity (ft/s): %.0f    Vertical Offset (inches): %.2f    Horizontal Offset (inches): %.2f    ToF (seconds): %.2f\n", i, data->flight_data[i].velocity, data->flight_data[i].vertical_offset, data->flight_data[i].horizontal_offset, data->flight_data[i].time_of_flight);
    }
}

#endif