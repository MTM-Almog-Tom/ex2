//
// Created by tomgu on 07/06/2021.
//

#include <iostream>

class Complex
{
private:
    double real;
    double imaginary;
public:
    // classic constructor
    Complex(double re, double im)
    {
        real = re;
        imaginary = im;
    }

    Complex(Complex& other)
    {
        real = other.real;
        imaginary = other.imaginary;
    }

    Complex& operator=(const Complex& other)
    {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    double re() const
    {
        return real;
    }

    double im() const
    {
        return imaginary;
    }

    void setRe(double re)
    {
        real = re;
    }
};

std::ostream& operator<<(std::ostream& ostream, Complex& z)
{
    return ostream << z.re() << "+" << z.im() << "i";
}

int main()
{
    Complex z1(1,1);
    Complex z2 = z1;
    std::cout << z1 << std::endl;
    z1.setRe(2);
    std::cout << z2 << std::endl;
    z2 = z1;
    std::cout << z2 << std::endl;
}