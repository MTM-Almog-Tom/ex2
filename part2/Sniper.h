#ifndef SNIPER_H_
#define SNIPER_H_
#include "Character.h"
#include "Exceptions.h"
#include "Auxiliaries.h"
#include <memory>
#include <vector>
using std::shared_ptr;
using std::vector;
using namespace mtm;
namespace mtm
{
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
        std::shared_ptr<Character> clone() const override;             //virtual clone
        void characterAttack(const GridPoint &src_coordinates,
                             const GridPoint &dst_coordinates,
                             vector<vector<std::shared_ptr<Character>>> board,
                             int height, int width) override; //virtual attack
        void characterReload(const GridPoint &coordinates);   //virtual reload
        int getMovmentRange() const;                          // accessor function
        int getAttackAmmoCost() const;                        // accessor function
        ~Sniper();
    };
}
#endif