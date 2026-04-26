#ifndef POPULATIONS_H
#define POPULATIONS_H
#include <vector>

class Populations {
public:
    std::vector<int> coords;
    int compartment; // s = 1, e = 2, i = 3, r = 4

    Populations(std::vector<int> coords, int compartment);
};

#endif