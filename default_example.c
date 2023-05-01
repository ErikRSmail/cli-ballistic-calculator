#include "cli-ballistic-calculator.h"

int main(){
    struct ballistic_data *data = default_ballistic_data_init();
    struct print_options *options = default_options();
    print_ballistic_data(data, options);
}