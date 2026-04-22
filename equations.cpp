#include "equations.h"
#include "populations.h"

Equations::Equations(){}

// The coupled set of equations (7 - 10)
double Equations::ds_dt(double i, double s){
    return -beta * i * s;
}

double Equations::de_dt(double i, double s, double e){
    return (beta * i * s) - (sigma * e);
}

double Equations::di_dt(double e, double i){
    return (sigma * e) - (gamma * i);
}

double Equations::dr_dt(double i){
    return gamma * i;
}