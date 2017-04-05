#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
/* -----------------------------------------------------------------------------

FILE:              Polynomial.h

DESCRIPTION:       Specification for Polynomial class

COMPILER:          gcc 5.4.0 -std=C++11

NOTES:             None

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
Aaryna Irwin            2017-03-17         0.1 - Initial

----------------------------------------------------------------------------- */

// Macro definitions
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Includes
#include <iostream>

class Polynomial
{
    int deg;
    int cof[9];
public:
	// Default constructor
	Polynomial();

	// Overloaded constructor
	Polynomial(std::istream&);

	// Copy constructor
	Polynomial(const Polynomial&);

	// Default destructor (placeholder - nothing to destroy yet)
	virtual ~Polynomial();
	
	// Assignment operator overloads
	Polynomial& operator=(const Polynomial) noexcept;
	Polynomial operator+(const Polynomial&);
	Polynomial operator+=(const Polynomial& rVal) { return *this + rVal; };
	Polynomial operator-(const Polynomial&);
	Polynomial operator-=(const Polynomial& rVal) { return *this - rVal; };
	Polynomial operator*(const Polynomial&);
	Polynomial operator*=(const Polynomial& rVal) { return *this * rVal; };
	
	// Comparison operator overloads
	bool operator==(const Polynomial&);
	bool operator!=(const Polynomial& rVal) { return !(*this == rVal); };

	// Evaluation (function operator) overload
	int operator()(const int);

	// Friend functions for stream insertion/extraction
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend std::istream& operator>>(std::istream&, Polynomial&);
};
#endif // POLYNOMIAL_H
