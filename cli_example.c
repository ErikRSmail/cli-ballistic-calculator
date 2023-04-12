#include <stdio.h>
#include <stdlib.h>

#include "cli-ballistics.h"

int main(){
    struct ballistic_data *input = cli_init();
    print_flight_data(input, 100);
}