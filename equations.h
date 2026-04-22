#ifndef EQUATIONS_H
#define EQUATIONS_H

#include "populations.h"

class Equations {
private:
    double beta;
    double sigma;
    double gamma;

public:
    Equations();
    double ds_dt(double i, double s);
    double de_dt(double i, double s, double e);
    double di_dt(double e, double i);
    double dr_dt(double i);
};

#endif