#ifndef POPULATIONS_H
#define POPULATIONS_H

class Populations {
public:
    double s;
    double e;
    double i;
    double r;

    // Hardcode intial population statistics
    Populations(double s = 0.99, double e = 0.01, double i = 0, double r = 0);
    bool isValid(double tolerance  = 1e-3);
};

#endif