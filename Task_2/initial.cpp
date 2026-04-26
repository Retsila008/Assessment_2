#include "initial.h"
#include <random>
#include <set>
#include <cmath>

Initial::Initial(int env_size, int num_agents, double exposed_ratio)
    : env_size(env_size), num_agents(num_agents), exposed_ratio(exposed_ratio){}

void Initial::generateMatrix(){
    matrix.assign(env_size, std::vector<Populations*>(env_size, nullptr));
}

void Initial::placeAgents(){
    // Create random number generator
    std::random_device rng;
    std::mt19937 gen(rng());
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
            int compartment = (agent_count < exposed_count) ? 3 : 1;
            std::vector<int> coords  = {x, y};
            matrix[x][y] = new Populations(coords, compartment);
            occupied.insert({x, y});
            agent_count++;
        }
    }
}

int Initial::getEnvSize(){
    return env_size;
}