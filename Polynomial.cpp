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
#include <cmath>
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
	indefinite = 0;
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
	indefinite = 0;
	deg = 0;
	for (int i = 8; i >= 0; --i)
		cof[i] = 0;

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
	indefinite = in.indefinite;
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
	deg = rVal.deg;
	
	for (int i = deg; i >= 0; --i)
		cof[i] = rVal.cof[i];

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
	Polynomial lVal;

	// Set degree of result
	lVal.deg = MAX(deg, rVal.deg);

	// Add each coefficient of like terms
	for (int i = lVal.deg; i >= 0; --i)
		lVal.cof[i] = cof[i] + rVal.cof[i];

	return lVal;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator+=(const Polynomial&)
DESCRIPTION:       Overloaded compound addition assignment for Polynomial class
RETURNS:           Polynomial&
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator+=(const Polynomial& rVal)
{
	*this = *this + rVal;

	return *this;
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
	Polynomial lVal;
	
	// Set degree of result
	lVal.deg = MAX(deg, rVal.deg);

	// Subtract each coefficient of like terms
	for (int i = lVal.deg; i >= 0; --i)
		lVal.cof[i] = cof[i] - rVal.cof[i];

	return lVal;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator-=(const Polynomial&)
DESCRIPTION:       Overloaded compound subtr assignment for Polynomial class
RETURNS:           Polynomial&
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator-=(const Polynomial& rVal)
{
	*this = *this - rVal;

	return *this;
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
FUNCTION:          operator*=(const Polynomial&)
DESCRIPTION:       Overloaded compound multipl assignment for Polynomial class
RETURNS:           Polynomial&
NOTES:             None
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator*=(const Polynomial& rVal)
{
	*this = *this * rVal;

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator--()
DESCRIPTION:       Overloaded decrement operator
RETURNS:           Polynomial&
NOTES:             Differentiates polynomial
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator--()
{
	Polynomial prev(*this);
	cof[deg] = 0;
	deg -= 1;

	for (int i = deg; i >= 0; --i)
		cof[i] = prev.cof[i + 1] * (i + 1);

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator++()
DESCRIPTION:       Overloaded increment operator
RETURNS:           Polynomial&
NOTES:             Integrates polynomial
----------------------------------------------------------------------------- */
Polynomial& Polynomial::operator++()
{
	Polynomial prev(*this);
	deg += 1;
	++indefinite;

	for (int i = deg; i >= 0; --i)
		cof[i] = prev.cof[i - 1] / i;

	cof[0] = 0;

	return *this;
}
/* -----------------------------------------------------------------------------
FUNCTION:          operator++(int)
DESCRIPTION:       Overloaded increment operator
RETURNS:           int
NOTES:             Integrates polynomial
----------------------------------------------------------------------------- */
int Polynomial::operator++(int ignore)
{
	float result = 0;

	result = (*this)(upper) - (*this)(lower);

	return result;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator==(const Polynomial&)
DESCRIPTION:       Overloaded equivalency operator for Polynomial class
RETURNS:           bool
NOTES:             None
----------------------------------------------------------------------------- */
bool Polynomial::operator==(const Polynomial& rVal)
{
	// Return value buffer
	bool isEqual = false;
	
	if (deg == rVal.deg)
	{
		isEqual = true;
		for (int i = deg; i >= 0; --i)
		{
			if (cof[i] != rVal.cof[i])
				isEqual = false;
		}
	}	

	return isEqual;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator()(const int)
DESCRIPTION:       Overloaded function call operator for Polynomial class
RETURNS:           int
NOTES:             Evaluates polynomial at x = rVal
----------------------------------------------------------------------------- */
int Polynomial::operator()(const int val)
{
	int result = 0;

	for (int i = deg; i >= 0; --i)
		result += pow(val, deg - i) * cof[i];

	return result;
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
		if (out.cof[i] != 0 || out.indefinite)
		{
			if (i < out.deg)
			{
	   			if (out.cof[i] >= 0) os << " +";
				else os << ' ';
			}

			if (out.indefinite && i < out.indefinite)
			{
				char constant = 'B' + (out.indefinite - i);
				os << constant;
			}
			else os << out.cof[i];
			if (i > 1) os << "x^" << i;
			if (i == 1) os << 'x';
		}
    }

	return os;
}
