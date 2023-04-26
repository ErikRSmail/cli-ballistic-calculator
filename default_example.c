#include <stdio.h>
#include <stdlib.h>

#include "cli-ballistic-calculator.h"

int main(){
    struct ballistic_data *data = default_init();
    print_ballistic_data(data, 100);
}