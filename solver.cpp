# include "solver.h"
#include <cmath>
#include <iostream>

// Initialise the class
Solver::Solver(double dt, double t_end)
    : dt(dt), t_end(t_end){}

// Function for solving the coupled differential equations
Solution Solver::solveRK4(const Equations& eqs, const Populations& initial){
    Solution solution;
    
    Populations current_pop = initial;
    double t = 0.0;

    // Add initial states to vectors
    solution.times.push_back(t);
    solution.states.push_back(current_pop);

    // Loop through time steps calculating each seir at each point in time
    while(t < t_end){
        double k1_s = eqs.ds_dt(current_pop.i, current_pop.s);
        double k1_e = eqs.de_dt(current_pop.i, current_pop.s, current_pop.e);
        double k1_i = eqs.di_dt(current_pop.e, current_pop.i);
        double k1_r = eqs.dr_dt(current_pop.i);

        double k2_s = eqs.ds_dt(current_pop.i + 0.5 * dt * k1_i, current_pop.s + 0.5 * dt * k1_s);
        double k2_e = eqs.de_dt(current_pop.i + 0.5 * dt * k1_i, current_pop.s + 0.5 * dt * k1_s, current_pop.e + 0.5 * dt * k1_e);
        double k2_i = eqs.di_dt(current_pop.e + 0.5 * dt * k1_e, current_pop.i + 0.5 * dt * k1_i);
        double k2_r = eqs.dr_dt(current_pop.i + 0.5 * dt * k1_i);

        double k3_s = eqs.ds_dt(current_pop.i + 0.5 * dt * k2_i, current_pop.s + 0.5 * dt * k2_s);
        double k3_e = eqs.de_dt(current_pop.i + 0.5 * dt * k2_i, current_pop.s + 0.5 * dt * k2_s, current_pop.e + 0.5 * dt * k2_e);
        double k3_i = eqs.di_dt(current_pop.e + 0.5 * dt * k2_e, current_pop.i + 0.5 * dt * k2_i);
        double k3_r = eqs.dr_dt(current_pop.i + 0.5 * dt * k2_i);

        double k4_s = eqs.ds_dt(current_pop.i + dt * k3_i, current_pop.s + dt * k3_s);
        double k4_e = eqs.de_dt(current_pop.i + dt * k3_i, current_pop.s + dt * k3_s, current_pop.e + dt * k3_e);
        double k4_i = eqs.di_dt(current_pop.e + dt * k3_e, current_pop.i + dt * k3_i);
        double k4_r = eqs.dr_dt(current_pop.i + dt * k3_i);

        current_pop.s += (dt / 6.0) * (k1_s + 2 * k2_s + 2 * k3_s + k4_s);
        current_pop.e += (dt / 6.0) * (k1_e + 2 * k2_e + 2 * k3_e + k4_e);
        current_pop.i += (dt / 6.0) * (k1_i + 2 * k2_i + 2 * k3_i + k4_i);
        current_pop.r += (dt / 6.0) * (k1_r + 2 * k2_r + 2 * k3_r + k4_r);

        // Increment time 
        t += dt;

        // Add updated states to vectors
        solution.times.push_back(t);
        solution.states.push_back(current_pop);

        if(!current_pop.isValid()){
            std::cerr << "Error: population invalid at t = " << t << std::endl;
            break;
        }
    };

    return solution;
};