#ifndef Population_h
#define Population_h
#include<vector>
#include<algorithm>
//FOR CODEBLOCKS
//#include "Individual.h"
//#include "Individual.cpp"
//#include "XY.cpp"
//#include "ABCD.cpp"

//FOR ECLIPSE
#include "Individual.h"
#include "XY.h"
#include "ABCD.h"

#define crossoverRange 0.25

class Population{

protected:

    int initialPopulationSize;
    unsigned int parentPopulationSize;
    int populationType;
    float mutationRange;
    std::vector<Individual*> population;

public:

    Population();
    Population(int, int);
    ~Population();

    int size();
    void setFitness();
    float getFittest();
    void getMostFit();
    static bool fittestCriteria(Individual*, Individual*);
    void populationSort();

    void tournamentSelection(int);
    void crossover();
    void mutation();
    void setOffspringFitness();
    void createNextPopulation();
    friend std::ostream& operator<<(std::ostream&, const Population&);
};
#endif
