#ifndef SOLVER_H
#define SOLVER_H

#include "equations.h"
#include "populations.h"
#include <vector>

struct Solution {
        std::vector<double> times;
        std::vector<Populations> states;
    };

class Solver {
private: 
    double dt;
    double t_end;
    
public:
    Solver(double dt = 0.1, double t_end = 100.0);
    Solution solveRK4(const Equations& eqs, const Populations& initial);
};

#endif  