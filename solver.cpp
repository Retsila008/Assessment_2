# include "solver.h"
#include <cmath>

Solver::Solver(double dt, double t_end)
    : dt(dt), t_end(t_end){}

Solution Solver::solveRK4(const Equations& eqs, const Populations& initial){
    Solution solution;
    
    Populations current_pop = initial;
    double t = 0.0;

    solution.times.push_back(t);
    solution.states.push_back(current_pop);

    while(t < t_end){
        double k1_s = eqs.ds_dt(eqs.beta, current_pop.i, current_pop.s)

    
        t += dt;
    }

};