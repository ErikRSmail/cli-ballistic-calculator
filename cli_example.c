#include <stdio.h>
#include <stdlib.h>

#include "cli-ballistic-calculator.h"

int main(){
    struct ballistic_data *input = cli_init();
    print_ballistic_data(input, 100);
}