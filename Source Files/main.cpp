using namespace std;
#include <limits>

//FOR CODEBLOCKS
//#include "Population.h"
//#include "Population.cpp"
//#include "Individual.h"

//FOR ECLIPSE
#include "Population.h"

int main(){


    cout << "________________________________PART 1: TESTING_____________________________________"<<endl<<endl;

    cout << "PART 1.A: TESTING IDIVIDUAL TYPE 1, XY" << endl ;
	cout << "TESTING IDEAL VALUE" << endl;
    cout<< " The ideal XY individual has values: X=0, Y=0." << endl;
    //Solves Ackley's: -20* exp(-0.2 * sqrt(0.5 * (pow(X,2) + pow(Y,2)))) - exp(0.5 * (cos (2*M_PI*X) + cos (2*M_PI*Y))) + exp(1) + 20;
    Individual*  XYIndividual(new XY(0,0));
    XYIndividual->setFitness();
    cout << " Its fitness is: ";
   cout <<  XYIndividual->getFitness() << endl << endl;

	cout << "TESTING SETTING VALUE" << endl;
	cout << "Before setting X,Y: " << endl;
	cout << "X = " << XYIndividual->getX() <<  ", Y = "  << XYIndividual->getY() << endl;
	XYIndividual->setXY(1,2);
	cout << "After setting XY to 1 and 2: " << endl;
	cout << "X = " << XYIndividual->getX() <<  ", Y = "  << XYIndividual->getY() << endl << endl;

	cout << "TESTING SETTING FITNESS" << endl;
	cout << "Before setting fitness : " << endl;
	cout << "Fitness = " << XYIndividual->getFitness() << endl;
	XYIndividual->setFitness();
	cout << "After setting fitness : " << endl;
	cout << "Fitness = " << XYIndividual->getFitness() << endl << endl;

    cout << "PART 1.B: TESTING INDIVIDUAL TYPE 2, ABCD" << endl ;
	cout << "TESTING IDEAL VALUE" << endl;
    cout<< " The ideal ABCD individual has values: A=1, B=4, C=-20, D=-30." << endl;
    //Fittest equation : 1x^3 + 4x^2 - 20x -30
    Individual*  ABCDIndividual(new ABCD(1,4,-20,-30));
   ABCDIndividual->setFitness();
    cout << " Its fitness is: ";
   cout <<  ABCDIndividual->getFitness() << endl  << endl;

	cout << "TESTING SETTING VALUE" << endl;
	cout << "Before setting A,B,C,D: " << endl;
	cout << "A = " << ABCDIndividual->getA() <<  ", B = "  << ABCDIndividual->getB() << ", C = " << ABCDIndividual->getC() <<  ", D= "  << ABCDIndividual->getD() << endl;
	ABCDIndividual->setABCD(1,2,3,4);
	cout << "After setting XY to 1 ,2,3 and 4: " << endl;
	cout << "A = " << ABCDIndividual->getA() <<  ", B = "  << ABCDIndividual->getB() << ", C = " << ABCDIndividual->getC() <<  ", D= "  << ABCDIndividual->getD() << endl << endl;

	cout << "TESTING SETTING FITNESS" << endl;
	cout << "Before setting fitness : " << endl;
	cout << "Fitness = " << ABCDIndividual->getFitness() << endl;
	ABCDIndividual->setFitness();
	cout << "After setting fitness : " << endl;
	cout << "Fitness = " << ABCDIndividual->getFitness() << endl << endl;

    cout << "PART 2.A: TESTING POPULATION TYPE 1 : XY" << endl << endl;
	Population popXY(1,10);
	cout << "TESTING POPULATION SIZE" << endl;
	cout << "The current population size is " << popXY.size()<< endl <<endl;

	cout << "TESTING SETTING THE FITNESS" << endl;
	cout << "Before setting the fitness: " << endl;
	cout << popXY;
	popXY.setFitness();
	cout << "After setting the fitness: " << endl;
    cout << popXY << endl;

    cout << "TESTING TOURNAMENT SELECTION" << endl;
    cout << "Before tournament selection: " << endl;
	cout << popXY;
	popXY.tournamentSelection(5);
    cout << "After selecting 5 parents from tournament selection: " << endl;
    cout << popXY << endl;

    cout << "TESTING CROSSOVER" << endl;
    cout << "Before crossover: " << endl;
	cout << popXY;
	popXY.crossover();
    cout << "After crossover: " << endl;
    cout << popXY << endl;

    cout << "TESTING MUTATION" << endl;
    cout << "Before mutation: " << endl;
	cout << popXY;
	popXY.mutation();
    cout << "After mutation: " << endl;
    cout << popXY << endl;

    cout << "SETTING OFFSPRINGS' FITNESS" << endl;
    cout << "Before setting: " << endl;
	cout << popXY;
	popXY.setOffspringFitness();
    cout << "After setting: " << endl;
    cout << popXY << endl;

    cout << "SORTING THE POPULATION BY FITNESS" << endl;
    cout << "Before sorting: " << endl;
	cout << popXY;
	popXY.populationSort();
    cout << "After sorting: " << endl;
    cout << popXY << endl;
    //add more offsprings to have enough individuals for next population
	popXY.crossover();	popXY.mutation(); 	popXY.setOffspringFitness();
    popXY.crossover();	popXY.mutation(); 	popXY.setOffspringFitness();
    popXY.populationSort();
    cout << "CREATING THE NEXT POPULATION" << endl;
    cout << "Before  creating the next population: " << endl;
	cout << popXY;
	popXY.createNextPopulation();
    cout << "After creating the next population: " << endl;
    cout << popXY << endl;

    cout << "PART 2.B: TESTING POPULATION TYPE 2 : ABCD" << endl << endl;
	Population popABCD(2,7);
	cout << "TESTING POPULATION SIZE" << endl;
	cout << "The current population size is " << popABCD.size()<< endl <<endl;

	cout << "TESTING SETTING THE FITNESS" << endl;
	cout << "Before setting the fitness: " << endl;
	cout << popABCD;
	popABCD.setFitness();
	cout << "After setting the fittest: " << endl;
    cout << popABCD << endl;

    cout << "TESTING TOURNAMENT SELECTION" << endl;
    cout << "Before tournament selection: " << endl;
	cout << popABCD;
	popABCD.tournamentSelection(3);
    cout << "After selecting 3 parents from tournament selection: " << endl;
    cout << popABCD << endl;

    cout << "TESTING CROSSOVER" << endl;
    cout << "Before crossover: " << endl;
	cout << popABCD;
	popABCD.crossover();
    cout << "After crossover: " << endl;
    cout << popABCD << endl;

    cout << "TESTING MUTATION" << endl;
    cout << "Before mutation: " << endl;
	cout << popABCD;
	popABCD.mutation();
    cout << "After mutation: " << endl;
    cout << popABCD << endl;

    cout << "SETTING OFFSPRINGS' FITNESS" << endl;
    cout << "Before setting: " << endl;
	cout << popABCD;
	popABCD.setOffspringFitness();
    cout << "After setting: " << endl;
    cout << popABCD << endl;

    cout << "SORTING THE POPULATION BY FITNESS" << endl;
    cout << "Before sorting: " << endl;
	cout << popABCD;
	popABCD.populationSort();
    cout << "After sorting: " << endl;
    cout << popABCD << endl;
    //add more offsprings to have enough individuals for next population
	popABCD.crossover();	popABCD.mutation(); 	popABCD.setOffspringFitness();
    popABCD.crossover();	popABCD.mutation(); 	popABCD.setOffspringFitness();
    popXY.populationSort();
    cout << "CREATING THE NEXT POPULATION" << endl;
    cout << "Before  creating the next population: " << endl;
	cout << popABCD;
	popABCD.createNextPopulation();
    cout << "After creating the next population: " << endl;
    cout << popABCD << endl;

    cout<<"________________________________PART 2: ALGORITHM____________________________________"<<endl<<endl;
    //Default Parameters
    int populationType;
    int initialPopulationSize = 100;
    int parentPopulationSize = 10;
    float idealFitness = 0.001;
    int maxGenerations = 10;
    int numGenerations = 0;

    srand((unsigned)time(NULL));

    cout << "Welcome to the Genetic Algorithm. The ideal fitness is 0.001 for a population size of 100. The maximum number of generations is 30 000"<< endl;

	while(1) //inputs type of population
	{

        cout<<"Select the type of population (1) XY (2) ABCD:";
        cin >> populationType;

        if (cin.get() != '\n' || cin.fail()){

            cin.clear(); //clears input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores everything after the first character
            cout << "Invalid Command. Request Again."<<endl;

        }
        else if (populationType != 1 && populationType != 2)//checks for valid type
            cout<<"Not a valid type."<<endl;

        else
            break;
	}

    Population population(populationType,initialPopulationSize);
    cout << "Population size is " << population.size() << endl;
    population.setFitness();
    while (population.getFittest() > idealFitness && numGenerations < maxGenerations){//loops until fitness is found or exceed max generations

        population.tournamentSelection( parentPopulationSize );
        while (population.size() != initialPopulationSize*10 + parentPopulationSize){
            population.crossover();
            population.mutation();
            population.setOffspringFitness();
        }
        population.populationSort();
        population.createNextPopulation();
        cout << "Gen " << numGenerations << " | Fittest | ";
        population.getMostFit();
        cout << endl;
        numGenerations++;
    }

    if (population.getFittest() < idealFitness)
        cout << "Successful! " <<endl;

    else
        cout << "Unsuccessful" << endl;

    cout<< " The fittest individual in the last population has a fitness of ";
    population.getMostFit();

    while(1) //inputs type of population
	{

        cout<<"Enter -1 to end the program";
        cin >> populationType;

        if (cin.get() != '\n' || cin.fail()){

            cin.clear(); //clears input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores everything after the first character
            cout << "Invalid Command. Enter -1. "<<endl;

        }
        else if (populationType != -1)//checks for valid type
            cout<<"Invalid Command. Enter -1. "<<endl;

        else
            break;
	}

}
