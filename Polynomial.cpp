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
FUNCTION:          Polynomial(istream&)
DESCRIPTION:       Construct directly from the stream
RETURNS:           N/A
NOTES:             Constructs a polynomial from stream input
----------------------------------------------------------------------------- */
Polynomial::Polynomial(std::istream& in)
{
	in >> *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial(const Polynomial&)
DESCRIPTION:       Copy constructor function for Polynomial class
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
Polynomial::~Polynomial()
{
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
FUNCTION:          operator*(const Polynomial&)
DESCRIPTION:       Overloaded multiplication operator for Polynomial class
RETURNS:           Polynomial
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator*(const Polynomial& rVal)
{
	// Return value buffer
	Polynomial lVal;
	
	// Set degree of result
	lVal.deg = deg + rVal.deg;

	// Multiply each coefficient of like terms
	for (int i = deg; i >= 0; --i)
	{
		for (int j = rVal.deg; j >= 0; --j)
			lVal.cof[i + j] += cof[i] * rVal.cof[j];
	}

	return lVal;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator>>(istream&, Polynomial&)
DESCRIPTION:       Overloaded stream extraction operator for Polynomial class
RETURNS:           istream&
NOTES:             None
----------------------------------------------------------------------------- */
std::istream& operator>>(std::istream& is, Polynomial& in)
{
	is >> in.deg;

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
