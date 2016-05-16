#ifndef XY_h
#define XY_h

#include "Individual.h"

class XY: public Individual{
protected:
    float X;
    float Y;

public:
    XY();
    XY(float, float);
    ~XY();
    float getX();
    float getY();
    void setXY(const float, const float);
    void setFitness();
};
#endif
