/* -----------------------------------------------------------------------------

FILE:              Polynomial.cpp

DESCRIPTION:       Definition file for Polynomial class

COMPILER:          gcc 5.4.0 -std=C++11

NOTES:             None

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
Aaryna Irwin            2017-03-17         0.1 - Initial

----------------------------------------------------------------------------- */
#include <iostream>
#include "Polynomial.h"

/* -----------------------------------------------------------------------------
FUNCTION:          get_poly()
DESCRIPTION:       User input function
RETURNS:           Void function
NOTES:             None
----------------------------------------------------------------------------- */
void Polynomial::get_poly()
{
	std::cout << "\nEnter degree of polynomial: ";
	std::cin >> deg;

    std::cout << "\nEnter the " << deg+1 << " cofficients: ";

    for (int i = deg; i >= 0; --i)
        std::cin >> cof[i];
}

/* -----------------------------------------------------------------------------
FUNCTION:          display_poly()
DESCRIPTION:       Print function
RETURNS:           Void function
NOTES:             None
----------------------------------------------------------------------------- */
void Polynomial::display_poly()
{
    std::cout << "\n\t";

    for (int i = deg; i >= 0; --i)
    {
	if (i < deg)
	{
	    if (cof[i] >= 0) std::cout << " +";
	    else std::cout << " ";
	}
	std::cout << cof[i];

	if (i > 1) std::cout << "x^" << i;
	if (i == 1) std::cout << "x";
    }
    std::cout << std::endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator+(const Polynomial&)
DESCRIPTION:       Overloaded addition operator for Polynomial class
RETURNS:           Polynomial
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator+(const Polynomial& p1)
{
	Polynomial p2;

	p2.deg = MAX(deg, p1.deg);

	for (int i = p2.deg; i >= 0; --i)
		p2.cof[i] = cof[i] + p1.cof[i];

	return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator-(const Polynomial&)
DESCRIPTION:       Overloaded subtraction operator for Polynomial class
RETURNS:           Polynomial
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator-(const Polynomial& p1)
{
	Polynomial p2;

	p2.deg = MAX(deg, p1.deg);

	for (int i = p2.deg; i >= 0; --i)
		p2.cof[i] = cof[i] - p1.cof[i];

	return p2;
}
