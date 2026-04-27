#ifndef SIMULATION_H
#define SIMULATION_H
#include "initial.h"
#include "populations.h"
#include <vector>

class Simulation {
private:
    Initial initial;
    int num_steps;
    double beta;
    double sigma;
    double gamma;
    int seed;

public:
    Simulation(Initial& initial, int num_steps, double beta, double sigma, double gamma, int seed);
    void run();
    void step();
    void updateAgent(int x, int y);
    void saveMatrix(int step_number);
    std::vector <int> countCompartments();
    void saveCompartmentData(const std::vector<std::vector<int>>& compartment_counts);
};

#endif
