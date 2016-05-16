#include "XY.h"

XY::XY(){//default constructor sets X and Y randomly and fitness to -1
    X = (float)rand()*2*genomeRange/RAND_MAX - genomeRange;
    Y = (float)rand()*2*genomeRange/RAND_MAX - genomeRange;
    fitness = -1;
}

XY::XY(float inputX, float inputY){
    X = inputX;
    Y = inputY;
    fitness = -1;
}

XY::~XY(){

}

float XY::getX(){
   return X;
}

float XY::getY(){
   return Y;
}

void XY::setXY(const float X, const float Y){
   this->X = X;
   this->Y = Y;
}

void XY::setFitness(){//sets fitness according to Ackley's equation
   fitness= -20 * exp(-0.2 * sqrt(0.5 * (pow(X,2) + pow(Y,2)))) - exp(0.5 * (cos (2*M_PI*X) + cos (2*M_PI*Y))) + exp(1) + 20;
}
