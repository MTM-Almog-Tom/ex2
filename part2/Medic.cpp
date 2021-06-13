#include "Character.h"
#include "Auxiliaries.h"
#include "Medic.h"
#include <memory>
using std::shared_ptr;
using namespace mtm;

Medic::Medic(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team) {} //constructor
Medic::Medic(const Medic &copy_from) : Character(copy_from) {}                                                       //copy constructor

Medic &Medic::operator=(const Medic &copy_from)
{
    Character::operator=(copy_from);
    return *this;
}

std::shared_ptr<Character> Medic::clone() const
{
    shared_ptr<Character> ptr(new Medic(*this));
    return ptr;
}

//geters
int Medic::getMovmentRange() const
{
    return movment_range;
}
int Medic::getLoadAmmo() const
{
    return load_ammo;
}
int Medic::getAttackAmmoCost() const
{
    return attack_ammo_cost;
}
Medic::~Medic()
{
    //לא לשכוח את האב
}