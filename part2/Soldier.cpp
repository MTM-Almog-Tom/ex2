#include "Soldier.h"
#include "Character.h"
#include <memory>
#include "Auxiliaries.h"

using namespace mtm;
using std::shared_ptr;

Soldier::Soldier(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team) {} //constructor

Soldier::Soldier(const Soldier &copy_from) : Character(copy_from)
{
} //copy constructor

Soldier &Soldier::operator=(const Soldier &copy_from)
{
    Character::operator=(copy_from);
    return *this;
}

shared_ptr<Character> Soldier::clone() const
{
    shared_ptr<Character> ptr(new Soldier(*this));
    return ptr;
}

//geters
int Soldier::getMovmentRange() const
{
    return movment_range;
}
int Soldier::getLoadAmmo() const
{
    return load_ammo;
}
int Soldier::getAttackAmmoCost() const
{
    return attack_ammo_cost;
}

Soldier::~Soldier()
{
    //לא לשכוח את האב
}