#include "Mutant.h"
#include "SurvivorCamp.h" // Needed for Replicator.
#include "Survivor.h"   // Needed for Spitter
#include <iostream>
using namespace std;

// ----- Mutant Base Implementation -----

Mutant::Mutant(const std::string &id, int health, int damage)
    : Combatant(id), health(health), damage(damage) {}

bool Mutant::IsDead() const {
    return health <= 0;
}

int Mutant::GetHealth() const {
    return health;
}

int Mutant::GetDamage() const {
    return damage;
}

void Mutant::setHealth(int newHealth) {
    health = newHealth;
}

void Mutant::setDamage(int newDamage) {
    damage = newDamage;
}

// ----- Zombie Implementation -----

Zombie::Zombie(const std::string &id, int health, int damage)
    : Mutant(id, health, damage) {}

void Zombie::TakeTurn(Combatant* target) {
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);
}

void Zombie::ReceiveAttack(int dmg) {
    setHealth(health - dmg);
    cout << GetID() << " takes " << dmg << " damage. Health = " << GetHealth() << endl;
}

//Replicator -subclass Mutant
//attacks every turn and creates copy of itself every turn
//inherits state from turn like current health
//replicators created by replicators can replicate themselves
//clones are added at the end of remainingMutants vector
//need pointer to its survivor camp to add new mutants to the encounter list


//come back to this
Replicator::Replicator(const std::string &id, int health, int damage, SurvivorCamp* ptrCamp)
    :Mutant(id, health, damage), turnCounter(0), _camp(ptrCamp){}

//copy constructor
Replicator::Replicator(const Replicator& other)
    :Mutant(other.GetID(), other.health, other.damage),_camp(other._camp),turnCounter(0){}

void Replicator::TakeTurn(Combatant* target) {
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);
    if((turnCounter % 2 == 0) && _camp != nullptr){
        Replicator *clone = new Replicator(*this);//need the copy constructor for this
        cout << GetID() << " creates clone " << endl;
    }else if (_camp == nullptr){
        cerr << GetID() << " has no camp  pointer " << endl;
    }
    turnCounter++;
}


void Replicator::ReceiveAttack(int dmg) {
    setHealth(health-dmg);
    cout << GetID() << " takes " << dmg << " damage. Health = " << GetHealth() << endl;
}


//splitter
Splitter::Splitter(const std::string &id, int health, int damage)
    :Mutant(id, health, damage),turnCounter(0),acidStatus(false) {}


void Splitter::TakeTurn(Combatant* target){
    if(turnCounter % 2 == 0){
        acidStatus = true;
        cout << GetID() << " gives poison" << endl;
    }
    else{
        cout << GetID() << " attacks " << target->GetID() << ". ";
        target->ReceiveAttack(damage);
    }
    turnCounter++;
}

void Splitter::ReceiveAttack(int dmg){
    setHealth(health-dmg);
    cout << GetID() << " takes " << dmg << " damage. Health = " << GetHealth() << endl;  
}

//mutantpack
MutantPack::MutantPack(const std::string &id, int health, int damage)
    :Mutant(id, health, damage), mutantsInPack() {}


bool MutantPack::IsDead() const{
    return mutantsInPack.empty();
} 
void MutantPack::AddMutant(Mutant* mutant) {
    mutantsInPack.push_back(mutant);
}

void MutantPack::TakeTurn(Combatant* target){
    for(auto* n: mutantsInPack){
        if(!n->IsDead()){
            target->ReceiveAttack(damage);
        }
    }
}

void MutantPack::ReceiveAttack(int dmg){
    if(!mutantsInPack.empty()){
        mutantsInPack.front()->ReceiveAttack(dmg);
        if(mutantsInPack.front()->IsDead()){
            delete mutantsInPack.front();
            mutantsInPack.erase(mutantsInPack.begin());
            if(mutantsInPack.empty()){
                cout << GetID() << " has been defeated " << endl;
            }
        }
    }
}

