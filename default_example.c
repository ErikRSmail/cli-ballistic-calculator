#include <stdio.h>
#include <stdlib.h>

#include "cli-ballistics.h"

int main(){
    struct ballistic_data *data = default_init();
    unsigned int step_size = 100;
    print_flight_data(data, 100);
}