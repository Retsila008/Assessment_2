#ifndef EQUATIONS_H
#define EQUATIONS_H

#include "populations.h"

class Equations {
public:
    double beta;
    double sigma;
    double gamma;

    Equations();
    double ds_dt(double beta, double i, double s);
    double de_dt(double beta, double sigma, double i, double s, double e);
    double di_dt(double sigma, double gamma, double e, double i);
    double dr_dt(double gamma, double i);
};

#endif