#include "ABCD.h"

ABCD::ABCD(){//default constructor sets A,B,C and D randomly and fitness to -1
    A = (float)rand()*2*genomeRange/RAND_MAX - genomeRange;
    B = (float)rand()*2*genomeRange/RAND_MAX - genomeRange;
    C = (float)rand()*2*genomeRange/RAND_MAX - genomeRange;
    D = (float)rand()*2*genomeRange/RAND_MAX - genomeRange;
    fitness = -1;
}

ABCD::ABCD(const float A, const float B, const float C, const float D){
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    fitness = -1;
}

ABCD::~ABCD(){

}


float ABCD::getA(){
   return A;
}

float ABCD::getB(){
   return B;
}

float ABCD::getC(){
   return C;
}

float ABCD::getD(){
   return D;
}

void ABCD::setABCD(const float A, const float B, const float C, const float D){
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

void ABCD::setFitness(){//sets fitness according to MSE
    //Fittest equation : 1x^3 + 4x^2 - 20x -30
    float error (0), errorsum(0), X, Y;
    float arr[23]= {-15, -10 -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    for (int i =0 ; i < 23 ; i++){
        X = arr[i];
        Y = pow(X,3) + 4*pow(X,2) - 20*X - 30;
        error = Y -  ( A*pow(X,3) + B*pow(X,2) + C*X + D );
        errorsum += pow(error,2);
    }
    fitness = errorsum /23;
}



