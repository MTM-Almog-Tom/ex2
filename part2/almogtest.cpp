#include <iostream>
#include <cassert>
#include "Exceptions.h"
#include "Auxiliaries.h"
#include "Game.h"

using namespace mtm;

void example1();
void example2();

int main()
{
    example1();
    //example2();
}

void example1()
{
    std::cout << "------example 1------" << std::endl;
    Game g1(8, 8);
    Game g2 = g1;
    g1.addCharacter(GridPoint(1, 1), Game::makeCharacter(CharacterType::MEDIC, Team::POWERLIFTERS, 10, 2, 4, 5));
    g1.addCharacter(GridPoint(1, 4), Game::makeCharacter(CharacterType::SNIPER, Team::POWERLIFTERS, 10, 2, 4, 5));
    g1.addCharacter(GridPoint(6, 1), Game::makeCharacter(CharacterType::SOLDIER, Team::CROSSFITTERS, 10, 2, 4, 5));
    g1.addCharacter(GridPoint(6, 4), Game::makeCharacter(CharacterType::MEDIC, Team::CROSSFITTERS, 10, 2, 4, 5));
    //std::cout << g1 << std::endl;
}