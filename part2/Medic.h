#ifndef MEDIC_H_
#define MEDIC_H_
#include "Character.h"
#include "Auxiliaries.h"
#include <memory>

using namespace mtm;
// const int MOVMENT_RANGE = 5;
// const int LOAD_AMMO = 5;
// const int ATTACK_AMMO_COST = 1;

class Medic : public Character
{
private:
    const int movment_range = 5;
    const int load_ammo = 5;
    const int attack_ammo_cost = 1;

public:
    Medic(int health, int ammo, int range, int power, Team team); //constructor
    Medic(const Medic &copy_from);                                //copy constructor
    Medic &operator=(const Medic &copy_from);                     //copy assignment
    virtual std::shared_ptr<Character> clone() const override;    // clone
    int getMovmentRange() const override;                         // accessor function
    int getLoadAmmo() const override;                             // accessor function
    int getAttackAmmoCost() const override;                       // accessor function
    ~Medic();
};

#endif