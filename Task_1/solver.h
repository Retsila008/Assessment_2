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
// Don't want to accidently edit these so they are private
private: 
    double dt;
    double t_end;

public:
    Solver(double dt, double t_end);
    Solution solveRK4(const Equations& eqs, const Populations& initial);
};

#endif  