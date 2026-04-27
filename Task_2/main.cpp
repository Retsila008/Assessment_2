#include <iostream>
#include <fstream>
#include "initial.h"
#include "simulation.h"

int main(){
    int env_size;
    int num_agents;
    double exposed_ratio;
    int num_steps;
    double beta;
    double sigma;
    double gamma;
    int seed;
    

    // Take input values for paramaters to ensure maintable code
    std::cout << "Enter value for environment size (must be whole number): ";
    std::cin >> env_size;
    std::cout << "Enter value for number of agents ";
    std::cin >> num_agents;
    std::cout << "Enter value for initial exposed ratio (0.0 - 1.0): ";
    std::cin >> exposed_ratio;
    std::cout << "Enter value for number of steps (must be whole number): ";
    std::cin >> num_steps;
    std::cout << "Enter value for beta: ";
    std::cin >> beta;
    std::cout << "Enter value for sigma: ";
    std::cin >> sigma;
    std::cout << "Enter value for gamma: ";
    std::cin >> gamma;
    std::cout << "Enter value for seed: ";
    std::cin >> seed;


    // Create instances of classes
    Initial initial(env_size, num_agents, exposed_ratio, seed);
    initial.generateMatrix();
    initial.placeAgents();
    Simulation simulation(initial, num_steps, beta, sigma, gamma, seed);

    // Run the simulation
    simulation.run();

    return 0;
}
