#include <iostream>
#include <cassert>
#include "Exceptions.h"
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
    //std::cout << g1 << std::endl;
}