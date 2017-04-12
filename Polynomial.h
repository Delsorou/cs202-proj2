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

// Includes
#include <vector>
#include <iostream>

// Forward declaration for templated friend function
template <class T>
class Polynomial;

// Friend function prototypes
template <class T>
std::ostream& operator<<(std::ostream&, const Polynomial<T>&);
template <class T>
std::istream& operator>>(std::istream&, Polynomial<T>&);

template <class T>
class Polynomial
{
	int indefinite;
	T upper;
	T lower;
    int deg;
	std::vector<T> cof;
public:
	// Default constructor
	Polynomial();

	// Overloaded constructor
	Polynomial(std::istream&);

	// Copy constructor
	Polynomial(const Polynomial<T>&);

	// Default destructor (placeholder - nothing to destroy yet)
	virtual ~Polynomial();
	
	// Operator overloads
	Polynomial<T>& operator=(const Polynomial<T>&);
	Polynomial<T>& operator=(Polynomial<T>&&) noexcept;
	Polynomial<T> operator+(const Polynomial<T>&);
	Polynomial<T>& operator+=(const Polynomial<T>&);
	Polynomial<T> operator-(const Polynomial<T>&);
	Polynomial<T>& operator-=(const Polynomial<T>&);
	Polynomial<T> operator*(const Polynomial<T>&);
	Polynomial<T>& operator*=(const Polynomial<T>&);

	// Increment/decrement overloads
	Polynomial<T>& operator--();
	Polynomial<T>& operator++();
	T operator++(int);
	
	// Comparison operator overloads
	bool operator==(const Polynomial<T>&);
	bool operator!=(const Polynomial<T>& rVal) { return !(*this == rVal); };

	// Evaluation (function operator) overload
	T operator()(const float);

	// Friend functions for stream insertion/extraction
	friend std::ostream& operator<<<T>(std::ostream&, const Polynomial<T>&);
	friend std::istream& operator>><T>(std::istream&, Polynomial<T>&);

	// Upper and lower limit acc/mut functions for definite integration
	void sUpper(T val) { upper = val; };
	void sLower(T val) { lower = val; };
	T gUpper() { return upper; };
	T gLower() { return lower; };
};
#include "Polynomial.tpp"
#endif // POLYNOMIAL_H
