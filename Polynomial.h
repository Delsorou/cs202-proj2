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
// #include <fstream>

class Polynomial
{
private:
    int deg;
    int cof[9];
public:
	Polynomial();
//	Polynomial(Polynomial&);
//	virtual ~Polynomial();
	Polynomial& operator=(const Polynomial) noexcept;
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);

	// Friend functions for stream insertion/extraction
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend std::istream& operator>>(std::istream&, Polynomial&);
//	friend std::ostream& operator<<(std::ofstream&, const Polynomial&);
//	friend std::istream& operator>>(std::ifstream&, Polynomial&);
};
#endif // POLYNOMIAL_H
