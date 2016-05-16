#ifndef ABCD_h
#define ABCD_h

#include "Individual.h"

class ABCD: public Individual{

protected:
    float A;
    float B;
    float C;
    float D;

public:
    ABCD();
    ABCD(const float, const float, const float, const float);
    ~ABCD();
    float getA();
    float getB();
    float getC();
    float getD();
    void setABCD(const float, const float, const float, const float);
    void setFitness();
};

#endif // ABCD_h
