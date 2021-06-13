#ifndef SOLDIER_H_
#define SOLDIER_H_
#include <memory>

#include "Character.h"
#include "Auxiliaries.h"

// const int MOVMENT_RANGE = 3;
// const int LOAD_AMMO = 3;
// const int ATTACK_AMMO_COST = 1;

class Soldier : public Character
{
private:
    const int movment_range = 3;
    const int load_ammo = 3;
    const int attack_ammo_cost = 1;

public:
    Soldier(int health, int ammo, int range, int power, Team team); //constructor
    Soldier(const Soldier &copy_from);                              //copy constructor
    Soldier &operator=(const Soldier &copy_from);                   //copy assignment
    virtual std::shared_ptr<Character> clone() const override;      //clone
    int getMovmentRange() const override;                           // accessor function
    int getLoadAmmo() const override;                               // accessor function
    int getAttackAmmoCost() const override;                         // accessor function
    ~Soldier();
};

#endif