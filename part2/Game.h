#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include "Character.h"
#include "Exceptions.h"
#include "Auxiliaries.h"
using std::vector;

class Game
{
private:
    int height;
    int width;
    vector<vector<std::shared_ptr<Character>>> board;

public:
    enum Team
    {
        POWERLIFTERS,
        CROSSFITTERS
    };
    enum CharacterType
    {
        SOLDIER,
        MEDIC,
        SNIPER
    };
    typedef int units_t;
    Game(int height, int width);                                                           //constructor
    Game(const Game &other);                                                               //copy constructor
    Game &operator=(const Game &other);                                                    //copy assignment
    void addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character); //Add Character
    static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                    units_t health, units_t ammo, units_t range, units_t power);
    void move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);
    void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates); // to check if to use typename to diff soldier with sniper&medic
    void reload(const GridPoint &coordinates);
    std::ostream &printGameBoard(std::ostream &os, const char *begin,
                                 const char *end, unsigned int width) const;
    bool isOver(Team *winningTeam = NULL) const;

    ~Game();
};

#endif