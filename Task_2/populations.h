#ifndef POPULATIONS_H
#define POPULATIONS_H
#include <vector>

class Populations {
public:
    std::vector<int> coords;
    int compartment; // s = 0, e = 1, i = 2, r = 3

    Populations(std::vector<int> coords, int compartment);
};

#endif