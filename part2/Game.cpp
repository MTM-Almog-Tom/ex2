#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include "Medic.h"
#include "Soldier.h"
#include "Sniper.h"
#include "Character.h"
#include "Game.h"
#include "Exceptions.h"
#include "Auxiliaries.h"

//constructor
Game::Game(int height, int width)
{
    if (height <= 0 || width <= 0)
    {
        throw mtm::IllegalArgument();
    }
    vector<vector<std::shared_ptr<Character>>> board(height, vector<std::shared_ptr<Character>>(width /*,initionlazation*/));
    this->board = board;
    this->height = height;
    this->width = width;
}
//copy constructor
Game::Game(const Game &other)
{
    board.resize(other.height);
    for (int i = 0; i < other.height; i++)
    {
        board[i].resize(other.width);
    }
    //this->board = other.board;
    for (int i = 0; i < other.height; i++)
    {
        for (int j = 0; j < other.width; j++)
        {
            if (other.board[i][j] != nullptr)
            {
                board[i][j] = other.board[i][j]->clone();
            }
        }
    }
    this->height = other.height;
    this->width = other.width;
}
//copy assignment
Game &Game::operator=(const Game &other)
{
    /*if(this->board == other.board) //need == to character
    {
        return *this;
    }
    */
    // maby need to delet
    for (int i = 0; i < other.height; i++)
    {
        for (int j = 0; j < other.width; j++)
        {
            if (other.board[i][j] != nullptr)
            {
                board[i][j] = other.board[i][j]->clone();
            }
        }
    }
    this->height = other.height;
    this->width = other.width;
    return *this;
}

void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character)
{
    if (character == nullptr)
    {
        return;
    }
    if (coordinates.row > height || coordinates.col > width || coordinates.row < 0 || coordinates.col < 0)
    {
        throw mtm::IllegalCell();
    }
    if (board[coordinates.row][coordinates.col] != nullptr)
    {
        throw mtm::CellOccupied();
    }
    this->board[coordinates.row][coordinates.col] = character;
}
static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                units_t health, units_t ammo, units_t range, units_t power)
{
    if (health <= 0 || ammo < 0 || power < 0 || range <= 0)
    {
        throw mtm::IllegalArgument();
    }
    switch (type)
    {
    case (SOLDIER):
        if (team == POWERLIFTERS)
        {
            std::shared_ptr<Character> ptr(new Soldier(health, ammo, range, power, POWERLIFTERS));
            return ptr;
        }
        else if (team = CROSSFITTERS)
        {
            std::shared_ptr<Character> ptr(new Soldier(health, ammo, range, power, CROSSFITTERS));
            return ptr;
        }
        break;
    case (SNIPER):
        if (team == POWERLIFTERS)
        {
            std::shared_ptr<Character> ptr(new Sniper(health, ammo, range, power, POWERLIFTERS));
            return ptr;
        }
        else if (team = CROSSFITTERS)
        {
            std::shared_ptr<Character> ptr(new Sniper(health, ammo, range, power, CROSSFITTERS));
            return ptr;
        }
        break;
    case (MEDIC):
        if (team == POWERLIFTERS)
        {
            std::shared_ptr<Character> ptr(new Medic(health, ammo, range, power, POWERLIFTERS));
            return ptr;
        }
        else if (team = CROSSFITTERS)
        {
            std::shared_ptr<Character> ptr(new Medic(health, ammo, range, power, CROSSFITTERS));
            return ptr;
        }
        break;
    default:
        break;
    }
    // return ptr;
}

Game::~Game()
{
}
