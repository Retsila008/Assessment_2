#include "equations.h"
#include "populations.h"

Equations::Equations(){}

// The coupled set of equations (7 - 10)
double Equations::ds_dt(double beta, double i, double s){
    return -beta * i * s;
}

double Equations::de_dt(double beta, double sigma, double i, double s, double e){
    return (beta * i * s) - (sigma * e);
}

double Equations::di_dt(double sigma, double gamma, double e, double i){
    return (sigma * e) - (gamma * i);
}

double Equations::dr_dt(double gamma, double i){
    return gamma * i;
}