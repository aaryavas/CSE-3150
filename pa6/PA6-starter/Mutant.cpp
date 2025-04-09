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
Replicator::Replicator(const std::string &id, int health, int damage, SurvivorCamp* camp)
    : Mutant(id, health, damage), turnCount(0), camp(camp) {}

//copy constructor - doesn't try something else
/*
Replicator::Replicator(const Replicator& other)
    :Mutant(other.GetID(), other.health, other.damage),_camp(other._camp),turnCounter(0){}
*/
void Replicator::TakeTurn(Combatant* target) {
    turnCount++;
    if(turnCount % 2 == 1) {
        Replicator* clone = new Replicator(GetID() + "_clone" + std::to_string(turnCount / 2 +1), health, damage, camp);
        camp->AddMutant(clone);
        cout << GetID() << " replicates itself, creating " << clone->GetID() << ". ";
    }
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);
}

void Replicator::ReceiveAttack(int dmg) {
    setHealth(health - dmg);
    cout << GetID() << " takes " << dmg << " damage. Health = " << GetHealth() << endl;
}


//splitter
Spitter::Spitter(const std::string &id, int health, int damage)
    : Mutant(id, health, damage), turnCount(0) {}

void Spitter::TakeTurn(Combatant* target) {
    turnCount++;
    if((turnCount - 1) % 2 == 0) {
        Survivor* surv = dynamic_cast<Survivor*>(target);
        if (surv) {
            surv->ApplyPoison();
        }
        cout << GetID() << " applies acid effect to " << surv->GetID() << ". \n";
    } else {
        cout << GetID() << " attacks " << target->GetID() << ". ";
        target->ReceiveAttack(damage);
    }
}

void Spitter::ReceiveAttack(int dmg) {
    setHealth(health - dmg);
    cout << GetID() << " takes " << dmg << " damage. Health = " << GetHealth() << endl;
}

//mutantpack
MutantPack::MutantPack(const std::string &id)
    : Mutant(id, 0, 0) {} // Pack-level health/damage not used.

MutantPack::~MutantPack() {
    for(Mutant* m : pack) {
        delete m;
    }
}

void MutantPack::AddMutant(Mutant* mutant) {
    pack.push_back(mutant);
}

void MutantPack::TakeTurn(Combatant* target) {
    // clean pack
    for (auto it = pack.begin(); it != pack.end(); ) {
        if ((*it)->IsDead()) {
            it = pack.erase(it);
        } else {
            ++it;
        }
    }
    
    cout << GetID() << " pack attacks " << target->GetID() << " with " << pack.size() << " mutants." << endl;
    for(Mutant* m : pack) {
        if(!m->IsDead()){
            m->TakeTurn(target);
        }
    }
}

void MutantPack::ReceiveAttack(int dmg) {
    for(Mutant* m : pack) {
        if(!m->IsDead()){
            m->ReceiveAttack(dmg);
            break;
        }
    }
}

bool MutantPack::IsDead() const {
    for(Mutant* m : pack) {
        if(!m->IsDead())
            return false;
    }
    return true;
}

