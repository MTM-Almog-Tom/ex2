#ifndef SOLDIER_H_
#define SOLDIER_H_
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
        std::shared_ptr<Character> clone() const override;              //virtual clone
        void characterAttack(const GridPoint &src_coordinates,
                             const GridPoint &dst_coordinates,
                             vector<vector<std::shared_ptr<Character>>> boardvc,
                             int height, int width);        //virtual attack
        void characterReload(const GridPoint &coordinates); //virtual reload
        int getMovmentRange() const;                        // accessor function
        int getAttackAmmoCost() const;                      // accessor function
        ~Soldier() override;
        char get_char() override;                           // virtual get char
    };
}
#endif
