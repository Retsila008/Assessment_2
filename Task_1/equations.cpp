#include "equations.h"
#include "populations.h"

Equations::Equations(double beta, double sigma, double gamma)
    : beta(beta), sigma(sigma), gamma(gamma){}

// The coupled set of equations (7 - 10)
double Equations::ds_dt(double i, double s) const{
    return -beta * i * s;
}

double Equations::de_dt(double i, double s, double e) const{
    return (beta * i * s) - (sigma * e);
}

double Equations::di_dt(double e, double i) const{
    return (sigma * e) - (gamma * i);
}

double Equations::dr_dt(double i) const{
    return gamma * i;
}