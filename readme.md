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
gcc -o cli-ballistics cli_example.c -lm && ./cli-ballistics
```

I would like to continue iterating on this, but this works and is nice and simple so I will leave this repo alone and continue elsewhere. 

Take a look at https://github.com/grimwm/libballistics. The data used for the numerical integrations here is straight from this library.