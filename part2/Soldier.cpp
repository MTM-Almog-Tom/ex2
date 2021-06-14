#include "Soldier.h"

#define s 's'

Soldier::Soldier(int health, int ammo, int range, int power, Team team) : Character(health, ammo, range, power, team) {} //constructor

Soldier::Soldier(const Soldier &copy_from) : Character(copy_from) {} //copy constructor

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
int Soldier::getAttackAmmoCost() const
{
    return attack_ammo_cost;
}
void Soldier::characterAttack(const GridPoint &src_coordinates,
                              const GridPoint &dst_coordinates,
                              vector<vector<std::shared_ptr<Character>>> board,
                              int height, int width)
{
    if ((src_coordinates.row != dst_coordinates.row) && (src_coordinates.col != dst_coordinates.col))
    {
        throw IllegalTarget();
    }
    if (ammo < attack_ammo_cost)
    {
        throw OutOfAmmo();
    }
    if (board[dst_coordinates.row][dst_coordinates.col]->getTeam() != this->getTeam())
    {
        board[dst_coordinates.row][dst_coordinates.col]->setHealth(-power);
        if (board[dst_coordinates.row][dst_coordinates.col]->getHealth() <= 0)
        {
            board[dst_coordinates.row].erase(board[dst_coordinates.row].begin() + dst_coordinates.col);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            shared_ptr<GridPoint> ptr(new mtm::GridPoint(i, j));
            if (mtm::GridPoint::distance(dst_coordinates, *ptr) <= (movment_range + 2) / 3)
            {
                if (dst_coordinates.row != i && dst_coordinates.col != j)
                {
                    if (board[i][j]->getTeam() != this->getTeam())
                    {
                        board[i][j]->setHealth(-((power + 1) / 2));
                        if (board[i][j]->getHealth() <= 0)
                        {
                            board[i].erase(board[i].begin() + j);
                        }
                    }
                }
            }
        }
    }
    ammo--;
}
void Soldier::characterReload(const GridPoint &coordinates)
{
    ammo = ammo + load_ammo;
}
Soldier::~Soldier()
{
    //לא לשכוח את האב
}

char get_char()
{
    return s;
}
