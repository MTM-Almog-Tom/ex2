#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <iostream>

namespace mtm
{
    class Exceptions : public std::exception
    {
    };
    class IllegalArgument : public Exceptions
    {
    };
    class IllegalCell : public Exceptions
    {
    };
    class CellEmpty : public Exceptions
    {
    };
    class MoveTooFar : public Exceptions
    {
    };
    class CellOccupied : public Exceptions
    {
    };
    class OutOfRange : public Exceptions
    {
    };
    class OutOfAmmo : public Exceptions
    {
    };
    class IllegalTarget : public Exceptions
    {
    };
}

#endif