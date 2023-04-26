#include <stdio.h>
#include <stdlib.h>

#include "src/calculations.h"
#include "src/io_functions.h"
#include "src/initializers.h"

int main(){
    struct ballistic_data *input = cli_init();
    print_ballistic_data(input, 100);
}