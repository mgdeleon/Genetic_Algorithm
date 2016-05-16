#include "Population.h"

Population::Population(){ //default constructor makes a population of type XY

    initialPopulationSize = 1000;
    parentPopulationSize = 100;
    mutationRange=1;
    populationType = 1;

     for (int i=0 ; i < initialPopulationSize ; i++)
            population.push_back(new XY);
}

Population::Population(int type, int inputPopSize){

    initialPopulationSize = inputPopSize;
    parentPopulationSize = initialPopulationSize/10;

    if (type == 1){//creates XY-type

        populationType = 1;
        mutationRange = 1;
        for (int i=0 ; i < inputPopSize ; i++)
            population.push_back(new XY);

    }

    if (type == 2){//creates ABCD

        populationType = 2;
        mutationRange = 0.01;
        for (int i=0 ; i < inputPopSize ; i++)
            population.push_back(new ABCD);

    }
}

Population::~Population(){ //clears population

     population.clear();//clears vector

}

int Population::size(){//returns current population size

    return population.size();

}

void Population::setFitness(){ //sets the whole population's fitness

    for (unsigned int i = 0 ; i < population.size() ; i++)
        population[i] -> setFitness();

}

float Population::getFittest(){//reutrns the fitness of the fittest individual

    return population[0]->getFitness();

}

 void Population::getMostFit(){//prints the parameters of the fittest individual in a population

    if ( populationType == 1 )//if XY-type

       std:: cout << "Fitness:"  << population[0]->getFitness() <<" | X:"  << population[0]->getX() << " | Y:"  << population[0]->getY();

    if ( populationType == 2 ){ //if ABCD type

        std::cout << "Fitness:"  << population[0]->getFitness();
        std::cout <<" | A:"  << population[0]->getA() << " | B:"  << population[0]->getB() <<" | C:"  << population[0]->getC() << " | D:"  << population[0]->getD();

    }
}

bool Population::fittestCriteria(Individual* i, Individual* j){//returns individual with lowest fitness as true

    return i->getFitness() < j->getFitness();

}

void Population::populationSort(){//sorts population according to fitness in ascending order

    std::sort(population.begin() , population.end(),fittestCriteria);

}

void Population::tournamentSelection(int parentPopulationSize){//selects parent population

    this->parentPopulationSize = parentPopulationSize;
    std::vector<Individual*> temp;//holds parents to go into crossover

    while( temp.size() < this->parentPopulationSize){

        int i1=(int)rand()%initialPopulationSize;
        int i2=(int)rand()%initialPopulationSize;
        int i3=(int)rand()%initialPopulationSize;//different parents are not picked in same selection
        while (i2 == i1)
            i2=(int)rand()%initialPopulationSize;
        while (i3 == i1 || i3 == i2)
            i3=(int)rand()%initialPopulationSize;
        //pushing first selected individual
        if (population[i1]->getFitness() < population[i2]->getFitness() && population[i1]->getFitness() < population[i3]->getFitness() )
            temp.push_back(population[i1]);
        //pushing second selected individual
        else if (population[i2]->getFitness() < population[i1]->getFitness() && population[i2]->getFitness() < population[i3]->getFitness() )
        	temp.push_back(population[i2]);
        //pushing third selected individual
        else if (population[i3]->getFitness() < population[i1]->getFitness() && population[i3]->getFitness() < population[i2]->getFitness() )
            temp.push_back(population[i3]);
    }

        for (unsigned int i = 0 ; i < temp.size() ; i++)//adds parents to the back of population
            population.push_back(temp[i]);

        temp.clear();//clears the temp

        population.erase(population.begin(), population.end() - this->parentPopulationSize);//erases initial population
}

void Population::crossover(){

    int i1=(int)rand()%parentPopulationSize;
    int i2=(int)rand()%parentPopulationSize;
    while (i2 == i1)//assures different parents
        i2=(int)rand()%parentPopulationSize;

    if (populationType == 1){//XY-type

        for (int i = 0 ; i <2 ; i++){//creates 2 offsprings

            float alphaX = (float)rand()*2*crossoverRange/RAND_MAX - crossoverRange;//random ratio
            float alphaY = (float)rand()*2*crossoverRange/RAND_MAX - crossoverRange;

            float X = population[i1]->getX() * alphaX + population[i2]->getX() * (1-alphaX);
            float Y = population[i1]->getY() * alphaY + population[i2]->getY() * (1-alphaY);

            population.push_back(new XY(X,Y));//sets new XY offspring according to ratio
        }
    }

    else if ( populationType == 2 ){//ABCD-type

        for (int i = 0 ; i <2 ; i++){//creates 2 offsprings

            float alphaA = (float)rand()*2*crossoverRange/RAND_MAX - crossoverRange;//random ratio
            float alphaB = (float)rand()*2*crossoverRange/RAND_MAX - crossoverRange;
            float alphaC = (float)rand()*2*crossoverRange/RAND_MAX - crossoverRange;
            float alphaD = (float)rand()*2*crossoverRange/RAND_MAX - crossoverRange;

            float A = population[i1]->getA() * alphaA + population[i2]->getA() * (1-alphaA);
            float B = population[i1]->getB() * alphaB + population[i2]->getB() * (1-alphaB);
            float C = population[i1]->getC() * alphaC + population[i2]->getC() * (1-alphaC);
            float D = population[i1]->getD() * alphaD + population[i2]->getD() * (1-alphaD);

            population.push_back(new ABCD(A,B,C,D));//sets new ABCD offspring accoring to ratio
        }
    }

}

void Population::mutation(){//adds noise

    if (populationType == 1){

        for (int i = 1; i<3 ; i++){//adds noise to last 2 individuals in population (last created offspring)

            float X = population[population.size()-i]->getX() + (float)rand()*2*mutationRange/RAND_MAX - mutationRange;
            float Y = population[population.size()-i]->getY() + (float)rand()*2*mutationRange/RAND_MAX - mutationRange;

            population[population.size()-i]->setXY(X,Y);

        }
    }

    else if (populationType == 2){

        for (int i = 1; i<3 ; i++){//adds noise to last 2 individuals in population (last created offspring)

            float A = population[population.size()-i]->getA() + (float)rand()*2*mutationRange/RAND_MAX - mutationRange;
            float B = population[population.size()-i]->getB() + (float)rand()*2*mutationRange/RAND_MAX - mutationRange;
            float C = population[population.size()-i]->getC() + (float)rand()*2*mutationRange/RAND_MAX - mutationRange;
            float D = population[population.size()-i]->getD() + (float)rand()*2*mutationRange/RAND_MAX - mutationRange;

            population[population.size()-i]->setABCD(A,B,C,D);

        }
    }
}

void Population::setOffspringFitness(){//sets the fitness of all the offsprings

    for (unsigned int i = population.size()-3; i < population.size() ; i++)
        population[i] -> setFitness();

}

void Population::createNextPopulation(){//creates the next population

     population.erase(population.begin() + initialPopulationSize, population.end());//clears vector
     for (std::vector<Individual* >::iterator it = population.begin() + initialPopulationSize ; it != population.end(); ++it)
		 delete (*it); //deallocates memory

}


std::ostream& operator<<(std::ostream& stream, const Population& pop){//prints entire population (for testing)

    if ( pop.populationType == 1 ){

        for (unsigned int i =0 ; i < pop.population.size() ; i++)
           stream << i<<" | Fitness:"  << pop.population[i]->getFitness() <<" | X:"  << pop.population[i]->getX() << " | Y:"  << pop.population[i]->getY()<<std::endl;

    }
     if ( pop.populationType == 2 ){

        for (unsigned int i =0 ; i < pop.population.size() ; i++){

           stream << i<<" | Fitness:"  << pop.population[i]->getFitness();
           stream <<" | A:"  << pop.population[i]->getA() << " | B:"  << pop.population[i]->getB() << " | C:"  << pop.population[i]->getC() << " | D:"  << pop.population[i]->getD()<<std::endl;

        }

    }
    return stream;
}
