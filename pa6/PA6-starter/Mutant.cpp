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
Replicator::Replicator(const std::string &id, int health, int damage)
    :Mutant(id, health, damage) {}

void Replicator::TakeTurn(Combatant* target) {
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);

}

void Replicator::ReceiveAttack(int dmg) {
    setHealth(health-dmg);
    cout << GetID() << " takes " << dmg << " damage. Health = " << GetHealth() << endl;
}


//splitter

//mutantpack



