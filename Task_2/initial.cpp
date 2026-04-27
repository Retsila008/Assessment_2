#include "initial.h"
#include <random>
#include <set>
#include <cmath>

// Constructor for the class
Initial::Initial(int env_size, int num_agents, double exposed_ratio, int seed)
    : env_size(env_size), num_agents(num_agents), exposed_ratio(exposed_ratio), seed(seed){}

// Create the matrix designating the lattice for the agents to move around on
void Initial::generateMatrix(){
    matrix.assign(env_size, std::vector<Populations*>(env_size, nullptr));
}

// Place the agents in random places on the lattice
void Initial::placeAgents(){
    // Create random number generator
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, env_size - 1);

    // Calculate the required number of infected agents
    std::set<std::pair<int, int>> occupied;
    int exposed_count = static_cast<int>(std::round(num_agents * exposed_ratio));
    int agent_count = 0;

    // Randomise agent locations
    while (agent_count < num_agents){
        int x = dis(gen);
        int y = dis(gen);
        
        // If the desired location is empty
        if (occupied.find({x, y}) == occupied.end()) {
            // Determine agents compartment
            int compartment = (agent_count < exposed_count) ? 2 : 1;
            std::vector<int> coords  = {x, y};
            // Create the instance of the agent in this location
            matrix[x][y] = new Populations(coords, compartment);
            occupied.insert({x, y});
            agent_count++;
        }
    }
}

// Getter function for env_size
int Initial::getEnvSize(){
    return env_size;
}