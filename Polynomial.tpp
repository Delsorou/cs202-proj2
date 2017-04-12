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
#include <vector>
#include <iostream>

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial()
DESCRIPTION:       Default constructor function for Polynomial class
RETURNS:           N/A
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>::Polynomial()
{
	indefinite = 0;
	upper = 0.0;
	lower = 0.0;
	deg = 0;
	cof.resize(deg + 1, 0.0);
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial(istream&)
DESCRIPTION:       Construct directly from the stream
RETURNS:           N/A
NOTES:             Constructs a polynomial from stream input
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>::Polynomial(std::istream& in)
{	
	indefinite = 0;
	upper = 0.0;
	lower = 0.0;
	deg = 0;
	cof.resize(deg + 1, 0.0);

	in >> *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial(const Polynomial<T>&)
DESCRIPTION:       Copy constructor function for Polynomial class
RETURNS:           N/A
NOTES:             Constructs a polynomial from another
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>::Polynomial(const Polynomial<T>& in)
{
	indefinite = in.indefinite;
	upper = in.upper;
	lower = in.lower;
	deg = in.deg;
	cof = in.cof;
}

/* -----------------------------------------------------------------------------
FUNCTION:          ~Polynomial()
DESCRIPTION:       Default destructor function for Polynomial class
RETURNS:           N/A
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>::~Polynomial()
{
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator=(const Polynomial<T>&)
DESCRIPTION:       Overloaded assignment operator for Polynomial class
RETURNS:           Polynomial<T>&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T>& rVal)
{
	if (this != &rVal)
	{
		deg = rVal.deg;
		indefinite = rVal.indefinite;
		upper = rVal.upper;
		lower = rVal.lower;
		cof = rVal.cof;
	}

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator=(const Polynomial<T>&&) noexcept
DESCRIPTION:       Overloaded assignment operator for Polynomial class
RETURNS:           Polynomial<T>&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator=(Polynomial<T>&& rVal) noexcept
{
	if (this != &rVal)
	{
		deg = rVal.deg;
		indefinite = rVal.indefinite;
		upper = rVal.upper;
		lower = rVal.lower;
		cof = rVal.cof;
	}

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator+(const Polynomial<T>&)
DESCRIPTION:       Overloaded addition operator for Polynomial class
RETURNS:           Polynomial<T>
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& rVal)
{
	// Return value buffer
	Polynomial<T> lVal;

	// Set degree of result
	lVal.deg = MAX(deg, rVal.deg);
	lVal.cof.resize(deg + 1, 0.0);

	// Add each coefficient of like terms
	for (int i = lVal.deg; i >= 0; --i)
		lVal.cof[i] = cof[i] + rVal.cof[i];

	return lVal;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator+=(const Polynomial<T>&)
DESCRIPTION:       Overloaded compound addition assignment for Polynomial class
RETURNS:           Polynomial<T>&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& rVal)
{
	*this = *this + rVal;

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator-(const Polynomial<T>&)
DESCRIPTION:       Overloaded subtraction operator for Polynomial class
RETURNS:           Polynomial<T>
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& rVal)
{
	// Return value buffer
	Polynomial<T> lVal;
	
	// Set degree of result
	lVal.deg = MAX(deg, rVal.deg);
	lVal.cof.resize(deg + 1, 0.0);

	// Subtract each coefficient of like terms
	for (int i = lVal.deg; i >= 0; --i)
		lVal.cof[i] = cof[i] - rVal.cof[i];

	return lVal;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator-=(const Polynomial<T>&)
DESCRIPTION:       Overloaded compound subtr assignment for Polynomial class
RETURNS:           Polynomial<T>&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial<T>& rVal)
{
	*this = *this - rVal;

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator*(const Polynomial<T>&)
DESCRIPTION:       Overloaded multiplication operator for Polynomial class
RETURNS:           Polynomial<T>
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& rVal)
{
	// Return value buffer
	Polynomial<T> lVal;
	
	// Set degree of result
	lVal.deg = deg + rVal.deg;
	lVal.cof.resize(lVal.deg + 1, 0.0);

	// Multiply each coefficient of like terms
	for (int i = deg; i >= 0; --i)
	{
		for (int j = rVal.deg; j >= 0; --j)
			lVal.cof[i + j] += cof[i] * rVal.cof[j];
	}

	return lVal;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator*=(const Polynomial<T>&)
DESCRIPTION:       Overloaded compound multipl assignment for Polynomial class
RETURNS:           Polynomial<T>&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial<T>& rVal)
{
	*this = *this * rVal;

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator--()
DESCRIPTION:       Overloaded decrement operator
RETURNS:           Polynomial<T>&
NOTES:             Differentiates polynomial
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator--()
{
	Polynomial<T> prev(*this);
	cof.resize(deg--, 0.0);

	for (int i = deg; i >= 0; --i)
		cof[i] = prev.cof[i + 1] * (i + 1);

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator++()
DESCRIPTION:       Overloaded increment operator
RETURNS:           Polynomial<T>&
NOTES:             Integrates polynomial
----------------------------------------------------------------------------- */
template <class T>
Polynomial<T>& Polynomial<T>::operator++()
{
	Polynomial<T> prev(*this);
	cof.resize(++deg + 1, 0.0);
	++indefinite;

	for (int i = deg + 1; i >= 0; --i)
		cof[i] = prev.cof[i - 1] / i;

	cof[0] = 0;

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator++(int)
DESCRIPTION:       Overloaded increment operator
RETURNS:           T
NOTES:             Definitely integrates polynomial
----------------------------------------------------------------------------- */
template <class T>
T Polynomial<T>::operator++(int ignore)
{
	T result = 0;

	result = (*this)(upper) - (*this)(lower);

	return result;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator==(const Polynomial<T>&)
DESCRIPTION:       Overloaded equivalency operator for Polynomial class
RETURNS:           bool
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
bool Polynomial<T>::operator==(const Polynomial<T>& rVal)
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
RETURNS:           T
NOTES:             Evaluates polynomial at x = param 
----------------------------------------------------------------------------- */
template <class T>
T Polynomial<T>::operator()(const float val)
{
	T result = 0;

	for (int i = deg; i >= 0; --i)
		result += pow(val, deg - i) * cof[i];

	return result;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator>>(istream&, Polynomial<T>&)
DESCRIPTION:       Overloaded stream extraction operator for Polynomial class
RETURNS:           istream&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
std::istream& operator>>(std::istream& is, Polynomial<T>& in)
{
	is >> in.deg;
	in.cof.resize(in.deg + 1, 0.0);

	for (int i = in.deg; i >= 0; --i)
		is >> in.cof[i];

	return is;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator<<(ostream&, const Polynomial<T>&)
DESCRIPTION:       Overloaded stream insertion operator for Polynomial class
RETURNS:           ostream&
NOTES:             None
----------------------------------------------------------------------------- */
template <class T>
std::ostream& operator<<(std::ostream& os, const Polynomial<T>& out)
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
				os << char('B' + out.indefinite - i);
				if (out.indefinite > out.indefinite - i && i > 1)
					os << '/' << i;
			}
			else os << out.cof[i];
			if (i > 1) os << "x^" << i;
			if (i == 1) os << 'x';
		}
    }

	return os;
}
