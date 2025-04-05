#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "Combatant.h"

// Base survivor class.
class Survivor : public Combatant {
public:
    Survivor(const std::string &id, int health, int damage);
    virtual ~Survivor() {}

    bool IsDead() const override;

    int GetHealth() const;
    int GetDamage() const;
    void ApplyPoison();
    void ProcessPoison();
    
protected:
    void setHealth(int newHealth);
    void setDamage(int newDamage);
    
    int health;
    int damage;
    int poisonCounter;
};

// --- Derived Survivor Types ---

// Scavenger: simply attacks the target.
class Scavenger : public Survivor {
public:
    Scavenger(const std::string &id, int health, int damage);
    void TakeTurn(Combatant* target) override;
    void ReceiveAttack(int damage) override;

};


// Brawler: attacks and gains damage +2 after attack
class Brawler: public Survivor{
public:
    Brawler(const std::string &id, int health, int damage);
    void TakeTurn(Combatant* target) override;
    void ReceiveAttack(int damage) override;    
};


// Acrobat - every four turns can dodge the next incoming attack
class Acrobat: public Survivor{
public:
    Acrobat(const std::string &id, int health, int damage);
    void TakeTurn(Combatant* target) override;
    void ReceiveAttack(int damage) override;
private:
    bool dodgeAvailable;
    int turnCounter;
    int dodgeAmount;
};

//medic- every 3 turns medic heals itself
class Medic: public Survivor{
public:
    Medic(const std::string &id, int health, int damage);
    void TakeTurn(Combatant* target) override;
    void ReceiveAttack(int damage) override;

private:
    bool healStatus;
    int turnCounter;
    bool healPoints;
};
#endif
