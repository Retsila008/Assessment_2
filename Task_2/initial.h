#ifndef INITIAL_H
#define INITIAL_H
#include <vector>
#include "populations.h"


class Initial {
private:
    int env_size;
    int num_agents;
    double inf_ratio;

public: 
    // This is public just so I don't have to write a getter function
    std::vector<std::vector<Populations*>> matrix;
    
    Initial(int env_size, int num_agents, double inf_ratio);
    void generateMatrix();
    void placeAgents();
};

#endif