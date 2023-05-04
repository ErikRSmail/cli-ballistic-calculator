#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <math.h>

#include "enums.h"
#include "structs.h"
#include "constants.h"

double bc_correction(struct environmental_data *environmental_data){
    double altitude_factor, temperature_factor, humidity_factor, pressure_factor;

    inline double calculate_humidity_factor(double temperature, double pressure, double relative_humidity) {
	    double vapor_pressure_weight = 4e-6*pow(temperature,3) - 0.0004*pow(temperature,2)+0.0234*temperature-0.2517;
	    double humidity_factor = 0.995*(pressure/(pressure-(0.3783)*(relative_humidity)*vapor_pressure_weight));
	    return humidity_factor;
    }
    inline double calculate_pressure_factor(double pressure) {
	    double pressure_factor = (pressure - STANDARD_PRESSURE)/(STANDARD_PRESSURE);
    	return pressure_factor;
    }
    inline double calculate_temperature_factor(double temperature, double altitude) {
	    double standard_temperature = -0.0036*altitude+STANDARD_TEMPERATURE;
	    double temperature_factor = (temperature-standard_temperature)/(459.6+standard_temperature);
	    return temperature_factor;
    }
    inline double calculate_altitude_factor(double altitude) {
	    double altitude_factor = -4e-15*pow(altitude,3)+4e-10*pow(altitude,2)-3e-5*altitude+1;
	    return (1/altitude_factor);
    }
    altitude_factor = calculate_altitude_factor(environmental_data->altitude);
    humidity_factor = calculate_humidity_factor(environmental_data->temperature, environmental_data->pressure, environmental_data->humidity);
    temperature_factor = calculate_temperature_factor(environmental_data->temperature, environmental_data->altitude);
    pressure_factor = calculate_pressure_factor(environmental_data->pressure);
    
    return altitude_factor * humidity_factor * (1 + temperature_factor - pressure_factor);
}

double decel(enum drag_model drag_model, double bc, double v){
    double dv, exp;
    if(drag_model == G1){
      if (v > 4230){ dv = 1.477404177730177e-04; exp = 1.9565; }
      else if (v> 3680) { dv = 1.920339268755614e-04; exp = 1.925 ; }
      else if (v> 3450) { dv = 2.894751026819746e-04; exp = 1.875 ; }
      else if (v> 3295) { dv = 4.349905111115636e-04; exp = 1.825 ; }
      else if (v> 3130) { dv = 6.520421871892662e-04; exp = 1.775 ; }
      else if (v> 2960) { dv = 9.748073694078696e-04; exp = 1.725 ; }
      else if (v> 2830) { dv = 1.453721560187286e-03; exp = 1.675 ; }
      else if (v> 2680) { dv = 2.162887202930376e-03; exp = 1.625 ; }
      else if (v> 2460) { dv = 3.209559783129881e-03; exp = 1.575 ; }
      else if (v> 2225) { dv = 3.904368218691249e-03; exp = 1.55  ; }
      else if (v> 2015) { dv = 3.222942271262336e-03; exp = 1.575 ; }
      else if (v> 1890) { dv = 2.203329542297809e-03; exp = 1.625 ; }
      else if (v> 1810) { dv = 1.511001028891904e-03; exp = 1.675 ; }
      else if (v> 1730) { dv = 8.609957592468259e-04; exp = 1.75  ; }
      else if (v> 1595) { dv = 4.086146797305117e-04; exp = 1.85  ; }
      else if (v> 1520) { dv = 1.954473210037398e-04; exp = 1.95  ; }
      else if (v> 1420) { dv = 5.431896266462351e-05; exp = 2.125 ; }
      else if (v> 1360) { dv = 8.847742581674416e-06; exp = 2.375 ; }
      else if (v> 1315) { dv = 1.456922328720298e-06; exp = 2.625 ; }
      else if (v> 1280) { dv = 2.419485191895565e-07; exp = 2.875 ; }
      else if (v> 1220) { dv = 1.657956321067612e-08; exp = 3.25  ; }
      else if (v> 1185) { dv = 4.745469537157371e-10; exp = 3.75  ; }
      else if (v> 1150) { dv = 1.379746590025088e-11; exp = 4.25  ; }
      else if (v> 1100) { dv = 4.070157961147882e-13; exp = 4.75  ; }
      else if (v> 1060) { dv = 2.938236954847331e-14; exp = 5.125 ; }
      else if (v> 1025) { dv = 1.228597370774746e-14; exp = 5.25  ; }
      else if (v>  980) { dv = 2.916938264100495e-14; exp = 5.125 ; }
      else if (v>  945) { dv = 3.855099424807451e-13; exp = 4.75  ; }
      else if (v>  905) { dv = 1.185097045689854e-11; exp = 4.25  ; }
      else if (v>  860) { dv = 3.566129470974951e-10; exp = 3.75  ; }
      else if (v>  810) { dv = 1.045513263966272e-08; exp = 3.25  ; }
      else if (v>  780) { dv = 1.291159200846216e-07; exp = 2.875 ; }
      else if (v>  750) { dv = 6.824429329105383e-07; exp = 2.625 ; }
      else if (v>  700) { dv = 3.569169672385163e-06; exp = 2.375 ; }
      else if (v>  640) { dv = 1.839015095899579e-05; exp = 2.125 ; }
      else if (v>  600) { dv = 5.71117468873424e-05 ; exp = 1.950 ; }
      else if (v>  550) { dv = 9.226557091973427e-05; exp = 1.875 ; }
      else if (v>  250) { dv = 9.337991957131389e-05; exp = 1.875 ; }
      else if (v>  100) { dv = 7.225247327590413e-05; exp = 1.925 ; }
      else if (v>   65) { dv = 5.792684957074546e-05; exp = 1.975 ; }
      else if (v>    0) { dv = 5.206214107320588e-05; exp = 2.000 ; }
    }
    else{
      if (v> 4200 ) {      dv = 1.29081656775919e-09; exp = 3.24121295355962; }
      else if (v> 3000 ) { dv = 0.0171422231434847  ; exp = 1.27907168025204; }
      else if (v> 1470 ) { dv = 2.33355948302505e-03; exp = 1.52693913274526; }
      else if (v> 1260 ) { dv = 7.97592111627665e-04; exp = 1.67688974440324; }
      else if (v> 1110 ) { dv = 5.71086414289273e-12; exp = 4.3212826264889 ; }
      else if (v>  960 ) { dv = 3.02865108244904e-17; exp = 5.99074203776707; }
      else if (v>  670 ) { dv = 7.52285155782535e-06; exp = 2.1738019851075 ; }
      else if (v>  540 ) { dv = 1.31766281225189e-05; exp = 2.08774690257991; }
      else if (v>    0 ) { dv = 1.34504843776525e-05; exp = 2.08702306738884; }
    }
    
    return dv * pow(v,exp) / bc;
}

double get_zero_angle(struct system_data *system_data) {
    double t,y,x,dt,da,v,vx,vy,vx1,vy1,dv,dvx,dvy,Gx,Gy,angle;
    t=0,y=0,x=0,dt=0,dt=0,v=0,vx=0,vy=0,vx1=0,vy1=0,dv=0,dvx=0,dvy=0,Gx=0,Gy=0,angle=0; 
    da = DEG_TO_RAD * 1;

    while(1){
        vy=system_data->muzzle_velocity*sin(angle);
        vx=system_data->muzzle_velocity*cos(angle);
        Gx=GRAVITY*sin(angle);
        Gy=GRAVITY*cos(angle);
        t=0;
        x=0;
        y=-(system_data->sight_height)/12;
        while (x<=system_data->zero_distance*3) {
            vy1=vy;
            vx1=vx;
            v=pow((pow(vx,2)+pow(vy,2)),0.5);
            dt=1/v;
            dv = decel(system_data->drag_model, system_data->bc, v);
            dvy = -dv*vy/v*dt;
            dvx = -dv*vx/v*dt;

            vx=vx+dvx;
            vy=vy+dvy;
            vy=vy+dt*Gy;
            vx=vx+dt*Gx;

            x=x+dt*(vx+vx1)/2;
            y=y+dt*(vy+vy1)/2;
   
            if (vy<0 && y<0) {
                break;
            }
            if (vy>3*vx) {
                break;
            }
            t += dt;
        }

        if (y>0 && da>0) {
            da = -da/2;
        }

        if (y<0 && da<0) {
            da = -da/2;
        }

        if (fabs(da) < 3e-6) break;
        if (angle > DEG_TO_RAD * 45) break;

        angle += da;
    }
  return RAD_TO_DEG * angle;
}

void calculate_flight_data(struct ballistic_data *input){
    input->system_data.bc *= bc_correction(&input->environmental_data);
    double zero_angle = get_zero_angle(&input->system_data);

    double gx = GRAVITY * sin(DEG_TO_RAD * (zero_angle + input->system_data.shooting_angle));
    double gy = GRAVITY * cos(DEG_TO_RAD * (zero_angle + input->system_data.shooting_angle));

    double vx = input->system_data.muzzle_velocity * cos(DEG_TO_RAD * zero_angle);
    double vy = input->system_data.muzzle_velocity * sin(DEG_TO_RAD * zero_angle);

    double headwind = input->environmental_data.wind_speed* cos(DEG_TO_RAD * input->environmental_data.wind_angle);
    double crosswind = input->environmental_data.wind_speed* sin(DEG_TO_RAD * input->environmental_data.wind_angle);

    double x = 0;
    double y = -(input->system_data.sight_height / 12);

    double dt, v, vx1, vy1, dv, dvx, dvy;
    double t = 0;
    int distance = 0;
    while(distance < MAX_DISTANCE){
        vx1 = vx;
        vy1 = vy;
        v = pow(pow(vx,2)+pow(vy,2),0.5);
        dt = 0.5/v;

        dv = decel(input->system_data.drag_model, input->system_data.bc, v+headwind);
        dvx = -(vx/v)*dv;
        dvy = -(vy/v)*dv;

        vx = vx + dt*dvx + dt*gx;
        vy = vy + dt*dvy + dt*gy;

        if(x/3 >= distance){
            input->flight_data[distance].velocity = v;
            input->flight_data[distance].vertical_offset = y * 12;
            input->flight_data[distance].horizontal_offset = (MPH_TO_INPERSEC * crosswind) * (t + dt - x/input->system_data.muzzle_velocity);
            input->flight_data[distance].time_of_flight = t+dt;
            distance++;
        }

        x = x + dt * (vx+vx1)/2;
        y = y + dt * (vy+vy1)/2;

        t += dt;
    }
}

#endif