#ifndef MUTANT_H
#define MUTANT_H

#include "Combatant.h"
#include <vector>
#include <string>

// Base mutant class.
class Mutant : public Combatant {
public:
    Mutant(const std::string &id, int health, int damage);
    virtual ~Mutant() {}

    bool IsDead() const override;

    int GetHealth() const;
    int GetDamage() const;
    
protected:
    void setHealth(int newHealth);
    void setDamage(int newDamage);
    
    int health;
    int damage;
};

// --- Derived Mutant Types ---

// Zombie: basic mutant that attacks every turn.
class Zombie : public Mutant {
public:
    Zombie(const std::string &id, int health, int damage);
    void TakeTurn(Combatant* target) override;
    void ReceiveAttack(int damage) override;
};

// Replicator: Creates copy of itself every turn - come back to this 
class Replicator : public Mutant {
public:
    Replicator(const std::string &id, int health, int damage);
    void TakeTurn(Combatant* target) override;
    void ReceiveAttack(int damage) override;
private:
    //some pointer maybe?

};

class 

#endif