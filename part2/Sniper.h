#ifndef SNIPER_H_
#define SNIPER_H_
#include "Character.h"
#include "Auxiliaries.h"
#include <memory>

// const int MOVMENT_RANGE = 4;
// const int LOAD_AMMO = 2;
// const int ATTACK_AMMO_COST = 1;

class Sniper : public Character
{
private:
    int attack_counter = 0;
    const int movment_range = 4;
    const int load_ammo = 2;
    const int attack_ammo_cost = 1;

public:
    Sniper(int health, int ammo, int range, int power, Team team); //constructor
    Sniper(const Sniper &copy_from);                               //copy constructor
    Sniper &operator=(const Sniper &copy_from);                    //copy assignment
    virtual std::shared_ptr<Character> clone() const override;     //clone
    int getMovmentRange() const override;                          // accessor function
    int getLoadAmmo() const override;                              // accessor function
    int getAttackAmmoCost() const override;                        // accessor function
    ~Sniper();
};

#endif