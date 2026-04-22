#ifndef EQUATIONS_H
#define EQUATIONS_H

class equations {
    private:
    double beta;
    double sigma;
    double gamma;
public:
    double normalise(double upper, double N);
    double ds_dt(double beta, double i, double s);
    double de_dt(double beta, double sigma, double i, double s, double e);
    double di_dt(double sigma, double gamma, double e, double i);
    double dr_dt(double gamma, double i);

    double get_R();
};

#endif