#include <stdio.h>

#include "cli-ballistic-calculator.h"

int main(){
    struct print_options *options;

    printf("\nDisplay calculated flight data with default options? (y/n) : ");
    char use_defaults = 'y';
    scanf(" %c", &use_defaults);
    if (use_defaults == 'y'){
        options = default_options();
    }
    else{
        options = cli_options_init();
    }
    
    struct ballistic_data *input = cli_ballistic_data_init();
    print_ballistic_data(input, options);
}