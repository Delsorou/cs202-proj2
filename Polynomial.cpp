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
FUNCTION:          operator>>(istream&, Polynomial&)
DESCRIPTION:       User input function
RETURNS:           Void function
NOTES:             None
----------------------------------------------------------------------------- */
std::istream& operator>>(std::istream& is, Polynomial& in)
{
	std::cout << "\nEnter degree of polynomial: ";
	is >> in.deg;

	std::cout << "\nEnter the " << in.deg + 1 << " cofficients: ";

	for (int i = in.deg; i >= 0; --i)
		is >> in.cof[i];

	return is;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator<<(ostream&, const Polynomial&)
DESCRIPTION:       Overloaded stream insertion operator for Polynomial class
RETURNS:           ostream&
NOTES:             None
----------------------------------------------------------------------------- */
std::ostream& operator<<(std::ostream& os, const Polynomial& out)
{
    for (int i = out.deg; i >= 0; --i)
    {
		if (i < out.deg)
		{
		   	if (out.cof[i] >= 0) os << " +";
			else os << " ";
		}
		os << out.cof[i];

		if (i > 1) os << "x^" << i;
		if (i == 1) os << "x";
    }

	return os;
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
