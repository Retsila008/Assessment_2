#include "initial.h"
#include <random>
#include <set>
#include <cmath>

Initial::Initial(int env_size, int num_agents, double inf_ratio)
    : env_size(env_size), num_agents(num_agents), inf_ratio(inf_ratio){}

void Initial::generateMatrix(){
    matrix.assign(env_size, std::vector<Populations*>(env_size, nullptr));
}