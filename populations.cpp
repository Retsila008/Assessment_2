#include "populations.h"

Populations::Populations(){

};

// Ensures the fractional populations sum to 1
bool Populations::isValid(double tolerance){
    if(s + e + i + r > 1 + tolerance){
        return false;
    }
    else if(s + e + i + r < 1 - tolerance){
        return false;
    }
    else{
        return true;
    }
}
