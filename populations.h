#ifndef POPULATIONS_H
#define POPULATIONS_H

class populations {
public:
    int s;
    int e;
    int i;
    int r;

    populations();
    bool isValid(double tolerance  = 1e-3);
};

#endif