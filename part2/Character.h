#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Auxiliaries.h"
#include <memory>
using namespace mtm;
using std::shared_ptr;

class Character
{
private:
    int health;
    int ammo;
    int range;
    int power;
    Team team;

public:
    Character(int health, int ammo, int range, int power, Team team); //constractor
    Character(const Character &copy_from);                            //copy constractor                                                                                                                      //copy constructor
    int getHealth() const;                                            // accessor function
    int getAmmo() const;                                              // accessor function
    int getRange() const;                                             // accessor function
    int getPower() const;                                             // accessor function
    Team getTeam() const;                                             // accessor function
    void setHealth(int health);                                       // accessor function
    void setAmmo(int ammo);                                           // accessor function
    virtual int getMovmentRange() const = 0;                          // virtual accessor function
    virtual int getLoadAmmo() const = 0;                              // virtual accessor function
    virtual int getAttackAmmoCost() const = 0;                        // virtual accessor function
    virtual shared_ptr<Character> clone() const = 0;                  //virtual clone
    virtual ~Character();                                             //virtual distructor
};

#endif