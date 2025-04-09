#include "SurvivorCamp.h"
#include "Survivor.h"
#include <iostream>
using namespace std;

//this will manage each round 

//SimulateCamp() - function to return number of turns 


//tell survivor to take turn


//check if Mutant is dead 

//after doing all this increment number of turns by one

//when AddMutant called we throwing new enemy into encounter 
//Mutants in the vector will attack in order, index 0 to last
SurvivorCamp::SurvivorCamp(Combatant* surv)
    : survivor(surv), turn(0) {}

SurvivorCamp::~SurvivorCamp() {
    for(Combatant* m : mutants) {
        delete m;
    }
}

int SurvivorCamp::SimulateCamp() {
    while(!survivor->IsDead() && !mutants.empty()){
        SimulateTurn();
        turn++;
    }
    return turn;
}

void SurvivorCamp::SimulateTurn() {
    Combatant* currentMutant = mutants.front();
    
    survivor->TakeTurn(currentMutant);
    if(currentMutant->IsDead()){
        std::cout << currentMutant->GetID() << " has been defeated." << std::endl;
        mutants.erase(mutants.begin());
        delete currentMutant;
    } else {
        currentMutant->TakeTurn(survivor);
    }
}

void SurvivorCamp::AddMutant(Combatant* mutant) {
    mutants.push_back(mutant);
}