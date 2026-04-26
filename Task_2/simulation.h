#ifndef SIMULATION_H
#define SIMULATION_H
#include "initial.h"
#include "populations.h"

class Simulation {
private:
    Initial initial;
    int num_steps;
    double beta;
    double sigma;
    double gamma;

public:
    Simulation(Initial& initial, int num_steps, double beta, double sigma, double gamma);
    void run();
    void step();
    void updateAgent(int x, int y);
};

#endif
