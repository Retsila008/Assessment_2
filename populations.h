#ifndef POPULATIONS_H
#define POPULATIONS_H

class Populations {
public:
    int s;
    int e;
    int i;
    int r;

    Populations();
    bool isValid(double tolerance  = 1e-3);
};

#endif