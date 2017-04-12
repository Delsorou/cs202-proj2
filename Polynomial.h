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
#include <vector>
#include <iostream>

class Polynomial
{
	int indefinite;
	float upper;
	float lower;
    int deg;
	std::vector<float> cof;
public:
	// Default constructor
	Polynomial();

	// Overloaded constructor
	Polynomial(std::istream&);

	// Copy constructor
	Polynomial(const Polynomial&);

	// Default destructor (placeholder - nothing to destroy yet)
	virtual ~Polynomial();
	
	// Operator overloads
	Polynomial& operator=(const Polynomial&);
	Polynomial& operator=(Polynomial&&) noexcept;
	Polynomial operator+(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);

	// Increment/decrement overloads
	Polynomial& operator--();
	Polynomial& operator++();
	float operator++(int);
	
	// Comparison operator overloads
	bool operator==(const Polynomial&);
	bool operator!=(const Polynomial& rVal) { return !(*this == rVal); };

	// Evaluation (function operator) overload
	float operator()(const float);

	// Friend functions for stream insertion/extraction
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend std::istream& operator>>(std::istream&, Polynomial&);

	// Upper and lower limit acc/mut functions for definite integration
	void sUpper(int val) { upper = val; };
	void sLower(int val) { lower = val; };
	float gUpper() { return upper; };
	float gLower() { return lower; };
};
#endif // POLYNOMIAL_H
