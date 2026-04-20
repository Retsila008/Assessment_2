#include "equations.h"



equations::equations(){}


double equations::dsdt(double beta, double I, double S, double N){
    return -beta * I * S / N;
}
