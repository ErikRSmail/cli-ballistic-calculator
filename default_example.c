#include <stdio.h>
#include <stdlib.h>

#include "src/calculations.h"
#include "src/io_functions.h"
#include "src/initializers.h"

int main(){
    struct ballistic_data *data = default_init();
    print_flight_data(data, 100);
}