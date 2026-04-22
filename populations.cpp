#include "populations.h"

populations::populations(){

};

// Ensures the fractional populations sum to 1
bool populations::isValid(double tolerance){
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
