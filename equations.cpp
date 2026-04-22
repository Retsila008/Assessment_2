#include "equations.h"

equations::equations(){}

double equations::normalise(double upper, double N){
    return upper / N;
}

double equations::ds_dt(double beta, double i, double s){
    return -beta * i * s;
}

double equations::de_dt(double beta, double sigma, double i, double s, double e){
    return (beta * i * s) - (sigma * e);
}

double equations::di_dt(double sigma, double gamma, double e, double i){
    return (sigma * e) - (gamma * i);
}

double equations::dr_dt(double gamma, double i){
    return gamma * i;
}