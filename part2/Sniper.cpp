#include "Sniper.h"
#include "Character.h"
#include "Auxiliaries.h"
#include <memory>
using namespace mtm;
using std::shared_ptr;

Sniper::Sniper(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team) {} //constructor
Sniper::Sniper(const Sniper &copy_from) : Character(copy_from) {}                                                      //copy constructor
Sniper &Sniper::operator=(const Sniper &copy_from)
{
    Character::operator=(copy_from);
    return *this;
}

shared_ptr<Character> Sniper::clone() const
{
    shared_ptr<Character> ptr(new Sniper(*this));
    return ptr;
}

//geters
int Sniper::getMovmentRange() const
{
    return movment_range;
}
int Sniper::getLoadAmmo() const
{
    return load_ammo;
}
int Sniper::getAttackAmmoCost() const
{
    return attack_ammo_cost;
}

Sniper::~Sniper()
{
    //לא לשכוח את האב
}