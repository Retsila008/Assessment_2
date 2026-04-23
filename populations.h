#ifndef POPULATIONS_H
#define POPULATIONS_H

class Populations {
public:
    double s;
    double e;
    double i;
    double r;

    Populations(double s = 0.99, double e = 0.0, double i = 0.01, double r = 0.0);
    bool isValid(double tolerance  = 1e-3);
};

#endif