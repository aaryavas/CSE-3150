#include "Survivor.h"
#include <iostream>
using namespace std;
#include "Mutant.h"
//survivor will perform one attack every turn

//behavior will be dependant on how subclass implements TakeTurn function

//TakeTurn
//takes mutant object, attacj with mutants RecieveAttack function



// ----- Survivor Base Implementation -----

Survivor::Survivor(const std::string &id, int health, int damage)
    : Combatant(id), health(health), damage(damage), poisonCounter(0) {}

bool Survivor::IsDead() const {
    return health <= 0;
}

int Survivor::GetHealth() const {
    return health;
}

int Survivor::GetDamage() const {
    return damage;
}

void Survivor::setHealth(int newHealth) {
    health = newHealth;
}

void Survivor::setDamage(int newDamage) {
    damage = newDamage;
}

void Survivor::ApplyPoison() {
    // If not already poisoned, set poison duration to 2 turns.
    if (poisonCounter == 0) {
        poisonCounter = 2;
    }
}

void Survivor::ProcessPoison() {
    // At the start of each turn, if poisoned, apply 2 damage and decrement the counter.
    if (poisonCounter > 0) {
        setHealth(health - 2);
        std::cout << GetID() << " takes 2 poison damage. ";
        poisonCounter--;
        if (poisonCounter == 0) {
            std::cout << GetID() << " is no longer poisoned. ";
        }
    }
}


// ----- Scavenger Implementation -----

Scavenger::Scavenger(const std::string &id, int health, int damage)
    : Survivor(id, health, damage) {}

void Scavenger::TakeTurn(Combatant* target) {
    ProcessPoison();
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);
}

void Scavenger::ReceiveAttack(int dmg) {
    setHealth(health - dmg);
    cout << GetID() << " receives " << dmg << " damage. Health = " << GetHealth() << endl;
}


//To implement:

//Brawler - subclass survivor
//every time killss a mutant, gains +2 damage for future attacks
Brawler::Brawler(const std::string &id, int health, int damage)
    : Survivor(id, health, damage) {}


void Brawler::TakeTurn(Combatant* target){
    ProcessPoison();
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);
    
    //this part may need to be repositioned and reworked to work work out later
    if(IsDead()){
        damage += 2;    
    }
}
void Brawler::ReceiveAttack(int dmg){
    setHealth(health- dmg);
    cout << GetID() << " recieves " << dmg << "damage. Health = " << GetHealth() << endl;
}



//acrobat - subclass survivor
//like scavenger but every four turns
//dodge ability on turn 0, again on turn 4 and 8
Acrobat::Acrobat(const std::string &id, int health, int damage)
    : Survivor(id, health, damage), dodgeAvailable(false), turnCounter(0), dodgeAmount(0){}

void Acrobat::TakeTurn(Combatant* target){
    ProcessPoison();
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);

    //need to implement dodge function every four turns 
    turnCounter++;
    if(turnCounter % 4 == 0){
        dodgeAvailable = true;
        dodgeAmount++;
    }
}
void Acrobat::ReceiveAttack(int dmg){
    if(!dodgeAvailable){
        setHealth(health-dmg);
        cout << GetID() << " recieves " << dmg << "damage. Health = " << GetHealth() << endl;
    }
    cout << GetID() << " dodge the attack! ";
}


Medic::Medic(const std::string &id, int health, int damage)
    :Survivor(id,health,damage), healStatus(false), turnCounter(0), healPoints(0){}
    
void Medic::TakeTurn(Combatant* target){
    if(turnCounter % 3 == 0){
        healStatus = true;
        poisonCounter = 0;
        health += 5; 
        cout << GetID() << " heals itself, the new health is " << health << ". "; 
    }
    ProcessPoison();
    cout << GetID() << " attacks " << target->GetID() << ". ";
    target->ReceiveAttack(damage);
    turnCounter++;
}

void Medic::ReceiveAttack(int dmg){
    setHealth(health-dmg);
    cout << GetID() << " recieves " << dmg << "damage. Health = "<< GetHealth() <<endl;
}

//medic -subclass survivor
//like survivor attacks first mutant every turn but is equipped with medical ability
//every 3 turns heals itself
//starts on turn 3,6, etc
//5 static health points, regardless of initial health amount
//if poisoned heals itself before and removes the effect of poison and will gain 5 health

