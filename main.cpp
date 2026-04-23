#include <iostream>
#include "equations.h"
#include "populations.h"
#include "solver.h"

int main(){
    double beta;
    double sigma;
    double gamma;

    // Take input values for paramaters to ensure maintable code
    std::cout << "Enter value for beta: ";
    std::cin >> beta;
    std::cout << "Enter value for sigma: ";
    std::cin >> sigma;
    std::cout << "Enter value for gamma: ";
    std::cin >> gamma;

    // Create instances of classes
    Equations eqs(beta, sigma, gamma);
    Populations initial;
    Solver solver(0.1, 100.0);

    // Run the solver function to solve the coupled differential equations
    Solution solution = solver.solveRK4(eqs, initial);
    
}
