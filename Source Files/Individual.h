#ifndef Individual_h
#define Individual_h

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>

#define genomeRange 100

class Individual{//default sets all parameters to 0
protected:
    double fitness;
public:
    virtual ~Individual();
    virtual void setFitness() = 0;
    float getFitness();

    virtual float getX();
    virtual float getY();
    virtual void setXY(const float, const float);
    virtual void setABCD(const float, const float, const float, const float);

    virtual float getA();
    virtual float getB();
    virtual float getC();
    virtual float getD();
};

#endif
