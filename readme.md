## What is this?
A barebones but functional ballistics calculator/library appropriate for mid/long range target shooting. 

It supports G1/G7 drag models. 

It takes as inputs: 
- bc
- muzzle velocity
- sight height
- shooting angle
- zero distance
- wind speed
- wind angle
- pressure
- temperature
- humidity
- altitude

If you just want to see it run and not mess with anything compile and run cli_example.c.
```
gcc -o cli-ballistics cli_example.c -lm -Wformat=0 && ./cli-ballistics
```
default_example.c exists for quick testing so that you don't have to go through the entire cli data entry process every time something is changed. If you don't want to use the cli interface and want to compile your input data in,
```
gcc -o default_example default_example.c -lm -Wformat=0 && ./default_example
``` 

Take a look at https://github.com/grimwm/libballistics. The data used for the numerical integrations here is straight from this library.