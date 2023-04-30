#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS H

#include <stdio.h>
#include <math.h>

#include "calculations.h"
#include "structs.h"
#include "constants.h"
#include "enums.h"

void print_flight_data(struct flight_datum *data, struct print_options *options){
    printf("\n=== Flight Data ===\n\n");

    inline double calculate_moa(double linear_correction, unsigned int distance){
        return atan2(linear_correction, (double)distance * YARD_TO_INCH) * RAD_TO_MOA;
    }

    inline double calculate_mil(double linear_correction, unsigned int distance){
        return atan2(linear_correction, (double)distance * YARD_TO_INCH) * RAD_TO_MILLIRAD;
    }

    for(int i = options->step_size; i <= options->max_distance; i+= options->step_size){
        printf("Distance (yards): %i    ", i);
        if(options->print_velocity){
            printf("Velocity (ft/s): %.0f    ", data[i].velocity);
        }
        if(options->print_vertical_correction){
            if(options->print_linear_correction){
                printf("Vertical Offset (inches): %.2f    ", data[i].vertical_offset);
            }
            if(options->print_moa_correction){
                printf("Vertical Offset (MOA): %.2f    ", calculate_moa(data[i].vertical_offset, i));
            }
            if(options->print_mil_correction){
                printf("Vertical Offset (MIL): %.2f    ", calculate_mil(data[i].vertical_offset, i));
            }

        }
        if(options->print_horizontal_correction){
            if(options->print_linear_correction){
                printf("Horizontal Offset (inches): %.2f    ", data[i].horizontal_offset);
            }
            if(options->print_moa_correction){
                printf("Horizontal Offset (MOA): %.2f    ", calculate_moa(data[i].horizontal_offset, i));
            }
            if(options->print_mil_correction){
                printf("Horizontal Offset (MIL): %.2f    ", calculate_mil(data[i].horizontal_offset, i));
            }
        }
        if(options->print_time_of_flight){
            printf("ToF (seconds): %.2f    ", data[i].time_of_flight);
        }
        printf("\n");
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

void print_ballistic_data(struct ballistic_data *data, struct print_options *options){
    if (options->print_system_data){
        print_system_data(&data->system_data);
    }
    if (options->print_environmental_data){
        print_environmental_data(&data->environmental_data);
    }
    if (options->print_flight_data){
        print_flight_data(data->flight_data, options);
    }
}
#endif