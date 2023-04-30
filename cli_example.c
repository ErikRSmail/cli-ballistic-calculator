#include <stdio.h>
#include <stdlib.h>

#include "cli-ballistic-calculator.h"

int main(){
    struct ballistic_data *input = cli_init();
    struct print_options *options = default_options();
    print_ballistic_data(input, options);
}