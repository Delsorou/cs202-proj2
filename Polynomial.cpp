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

// Includes
#include <iostream>
// #include <fstream>
#include "Polynomial.h"


/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial()
DESCRIPTION:       Default constructor function for Polynomial class
RETURNS:           N/A
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial::Polynomial()
{
	deg = 0;
	for (int i = 8; i >= 0; --i)
		cof[i] = 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial(Polynomial&)
DESCRIPTION:       Overloaded constructor function for Polynomial class
RETURNS:           N/A
NOTES:             Constructs a polynomial from another
----------------------------------------------------------------------------- */
Polynomial::Polynomial(const Polynomial& in)
{
	deg = in.deg;
	for (int i = deg; i >= 0; --i)
		cof[i] = in.cof[i];
}

/* -----------------------------------------------------------------------------
FUNCTION:          ~Polynomial()
DESCRIPTION:       Default destructor function for Polynomial class
RETURNS:           N/A
NOTES:             None
----------------------------------------------------------------------------- */
//Polynomial::~Polynomial()
//{
//}

/* -----------------------------------------------------------------------------
FUNCTION:          operator>>(ifstream&, Polynomial&)
DESCRIPTION:       Overloaded stream extraction operator for Polynomial class
RETURNS:           istream&
NOTES:             File input version
----------------------------------------------------------------------------- */
//std::istream& operator>>(std::ifstream& is, Polynomial& in)
//{
//	is >> in.deg;
//
//	for (int i = in.deg; i >= 0; --i)
//		is >> in.cof[i];
//
//	return is;
//}

/* -----------------------------------------------------------------------------
FUNCTION:          operator>>(istream&, Polynomial&)
DESCRIPTION:       Overloaded stream extraction operator for Polynomial class
RETURNS:           istream&
NOTES:             User input version
----------------------------------------------------------------------------- */
std::istream& operator>>(std::istream& is, Polynomial& in)
{
	std::cout << "\nEnter the degree of the polynomial: ";
	is >> in.deg;

	std::cout << "\nEnter the " << in.deg + 1 << " cofficient(s): ";

	for (int i = in.deg; i >= 0; --i)
		is >> in.cof[i];

	return is;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator<<(ofstream&, const Polynomial&)
DESCRIPTION:       Overloaded stream insertion operator for Polynomial class
RETURNS:           ostream&
NOTES:             File output version
----------------------------------------------------------------------------- */
//std::ostream& operator<<(std::ofstream& os, const Polynomial& out)
//{
//	for (int i = out.deg; i >= 0; --i)
//	{
//		if (i < out.deg)
//		{
//		   	if (out.cof[i] >= 0) os;
//			else os << " ";
//		}
//		os << out.cof[i];
//		if (i == 1) os << "x";
//	}
//
//	return os;
//}

/* -----------------------------------------------------------------------------
FUNCTION:          operator<<(ostream&, const Polynomial&)
DESCRIPTION:       Overloaded stream insertion operator for Polynomial class
RETURNS:           ostream&
NOTES:             Terminal output version
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
Polynomial Polynomial::operator+(const Polynomial& rVal)
{
	// Return value buffer
	Polynomial sum;

	// Set degree of result
	sum.deg = MAX(deg, rVal.deg);

	// Add each coefficient of like terms
	for (int i = sum.deg; i >= 0; --i)
		sum.cof[i] = cof[i] + rVal.cof[i];

	return sum;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator-(const Polynomial&)
DESCRIPTION:       Overloaded subtraction operator for Polynomial class
RETURNS:           Polynomial
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator-(const Polynomial& rVal)
{
	// Return value buffer
	Polynomial diff;
	
	// Set degree of result
	diff.deg = MAX(deg, rVal.deg);

	// Subtract each coefficient of like terms
	for (int i = diff.deg; i >= 0; --i)
		diff.cof[i] = cof[i] - rVal.cof[i];

	return diff;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator=(const Polynomial&)
DESCRIPTION:       Overloaded assignment operator for Polynomial class
RETURNS:           Polynomial
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator=(const Polynomial rVal) noexcept
{
	this->deg = rVal.deg;
	
	for (int i = this->deg; i >= 0; --i)
		this->cof[i] = rVal.cof[i];

	return *this;
}
