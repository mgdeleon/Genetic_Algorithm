#include "Individual.h"

Individual::~Individual(){

}

void Individual::setFitness(){
	fitness = -1;
}

float Individual::getFitness(){ //returns fitness
    return fitness;
}

float Individual::getX(){
    return -1;
}

float Individual::getY(){
    return -1;
}

void Individual::setXY(const float X, const float Y){
    return;
}

void Individual::setABCD(const float A, const float B, const float C, const float D){
	return;
}

float Individual::getA(){
    return -1;
}

float Individual::getB(){
    return -1;
}
float Individual::getC(){
    return -1;
}

float Individual::getD(){
    return -1;
}
