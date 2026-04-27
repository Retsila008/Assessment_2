// Import libraries
#include <iostream>
#include <fstream>
#include "equations.h"
#include "populations.h"
#include "solver.h"

void writeCSV(const std::string& filename, const Solution& solution);

int main(){
    // Initilaise variables for transition probabilities
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

    // Run the writeCSV function to add data to file
    writeCSV("task_1_data", solution);
};

// Function for adding data to file
void writeCSV(const std::string& filename, const Solution& solution) {
    std::ofstream file(filename);
    
    // Write header
    file << "time,s,e,i,r\n";
    
    // Write data
    for (size_t i = 0; i < solution.times.size(); ++i) {
        file << solution.times[i] << ","
             << solution.states[i].s << ","
             << solution.states[i].e << ","
             << solution.states[i].i << ","
             << solution.states[i].r << "\n";
    }
    // Close file
    file.close();
}
