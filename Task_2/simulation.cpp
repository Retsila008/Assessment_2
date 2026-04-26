#include "simulation.h"
#include <vector>
#include <iostream>
#include <random>
#include <cmath>

Simulation::Simulation(Initial& initial, int num_steps, double beta, double sigma, double gamma)
    : initial(initial), num_steps(num_steps), beta(beta), sigma(sigma), gamma(gamma){}

void Simulation::run(){
    // Go through time and run the simulation for each step
    for(int i = 0; i < num_steps; ++i){
        step();
    }
}

void Simulation::step(){
    // Scan through the matrix
    int env_size = initial.getEnvSize();
    for(int x = 0; x < env_size; x++){
        for(int y = 0; y < env_size; x++){
            // Update the angent only if there is one in that position
            if(initial.matrix[x][y] != nullptr){
                updateAgent(x, y);
            }
        }
    }
}

void Simulation::updateAgent(int x, int y){
    // ========== STEP A ==========
 
    // Create random number generator
    static std::random_device rng;
    static std::mt19937 gen(rng());
    std::uniform_int_distribution<> direction_dis(0, 7);
    std::uniform_real_distribution<> prob_dis(0.0, 1.0);

    // Locate desired agent
    int env_size = initial.getEnvSize();
    Populations* agent = initial.matrix[x][y];

    int direction = direction_dis(gen);
    int new_x = x;
    int new_y = y;

    // Move in the desired direction
    // add or subtract 1 as required
    // then mod with matrix dimension to ensure wraparound
    switch(direction){
        // Move up
        case 0:
            new_y = (y + 1) % env_size;
            break;
        // Move up-right
        case 1:
            new_x = (x + 1) % env_size;
            new_y = (y + 1) % env_size;
        // Move right
        case 2:
            new_x = (x + 1) % env_size;
        // Move down-right
        case 3:
            new_x = (x + 1) % env_size;
            new_y = (y - 1 + env_size) % env_size;
        // Move down
        case 4:
            new_y = (y - 1 + env_size) % env_size;
        // Move down-left
        case 5:
            new_x = (x - 1 + env_size) % env_size;
            new_y = (y - 1 + env_size) % env_size;
        // Move left
        case 6:
            new_x = (x - 1 + env_size) % env_size;
        // Move up-left
        case 7:
            new_x = (x - 1 + env_size) % env_size;
            new_y = (y + 1) % env_size;
    }

    // Ensure destination is not already occupied
    if (initial.matrix[new_x][new_y] == nullptr){
        initial.matrix[new_x][new_y] = agent;
        initial.matrix[x][y] = nullptr;
    }

    // Update co-ordinates
    agent -> coords[0] = new_x;
    agent -> coords[1] = new_y;

    // ========== STEP B ==========

    // Store variables rather than call them multiple times
    int compartment = agent -> compartment;
    double random_prob = prob_dis(gen);

    // Exposed becomes Infected
    if(compartment == 2){
        if(random_prob < sigma){
            agent -> compartment = 3;
        }
    }

    // Infected becomes recovered
    else if (compartment == 3){
        if(random_prob < gamma){
            agent -> compartment = 4;
        }
    }

    // ========== STEP C ==========

    // If suseptible, check for nearby infectious
    if(agent -> compartment == 1){
        //vector of each possible direction of movement
        std::vector<std::pair<int, int>> adjacents {
            {x, (y + 1) % env_size},
            {(x + 1) % env_size, (y + 1) % env_size},
            {(x + 1) % env_size, y},
            {(x + 1) % env_size, (y - 1 + env_size) % env_size},
            {x, (y - 1 + env_size) % env_size},
            {(x - 1 + env_size) % env_size, (y - 1 + env_size) % env_size},
            {(x - 1 + env_size) % env_size, y},
            {(x - 1 + env_size) % env_size, (y + 1) % env_size}
        };

        bool becoming_infected = false;
        // Check every direction in the vector
        for(auto& adjacents : adjacents){
            int nx = adjacents.first;
            int ny = adjacents.second;

            // Check for agent at location
            if(initial.matrix[nx][ny] != nullptr){
                // Check for infection
                if(initial.matrix[nx][ny] -> compartment == 3){
                    // Randomly infect, can use random_prob again as previous use is independent
                    if(random_prob < beta){
                        becoming_infected = true;
                        break;
                    }
                }
            }
        }

        if(becoming_infected = true){
            agent -> compartment = 2;
        }
    }
}