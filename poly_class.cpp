/* -----------------------------------------------------------------------------

FILE:              poly_class.cpp

DESCRIPTION:       Driver file to test Polynomial class

COMPILER:          gcc 5.4.0 -std=C++11

NOTES:             None

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
Aaryna Irwin            2017-03-17         0.1 - Initial

----------------------------------------------------------------------------- */

#include "Polynomial.h"
#include <iostream>
#include <iomanip>

#define F_1 setw(40)

/* -----------------------------------------------------------------------------
FUNCTION:          main(const int, const char**)
DESCRIPTION:       There your function.
RETURNS:           int
NOTES:             None
----------------------------------------------------------------------------- */
int main(const int argc, const char* argv[])
{
	using std::cout;
	using std::endl;
	using std::setw;

	// Demonstrate default and overloaded constructors
	cout << "Enter the degree and coefficients for the polynomial f(x): ";
	Polynomial* Poly0 = new Polynomial(std::cin);
	cout << endl;
	cout << "Enter the degree and coefficients for the polynomial g(x): ";
	Polynomial* Poly1 = new Polynomial(std::cin);
	cout << endl << endl;
	Polynomial* Poly2 = new Polynomial();

	cout << std::right << F_1 << "f(x) = " <<  *Poly0 << endl
		<< F_1 << "g(x) = " <<  *Poly1 << endl << endl;

	// Demonstrate addition and compound addition assignment
	cout << F_1 << "(f + g)(x) = " << *Poly0 + *Poly1 << endl;
	*Poly2 = *Poly0;
	*Poly2 += *Poly1;
	cout << F_1 << "(using +=): " << *Poly2 << endl << endl;

	// Demonstrate subtraction and compound subtraction assignment
	cout << F_1 << "(f - g)(x) = " << *Poly0 - *Poly1 << endl;
	*Poly2 = *Poly0;
	*Poly2 -= *Poly1;
	cout << F_1 << "(using -=): " << *Poly2 << endl << endl;

	// Demonstrate multiplication and compound multiplication assignment
	cout << F_1 << "Q(x) = (f * g)(x) = " << *Poly0 * *Poly1 << endl;
	*Poly2 = *Poly0;
	*Poly2 *= *Poly1;
	cout << F_1 << "(using *=): " << *Poly2 << endl << endl;

	// Demonstrate differentiation
	cout << F_1 << "Q'(x) = d/dx(Q(x)) = " << --*Poly2 << endl;
	cout << F_1 << "Q''(x) = d/dx(Q'(x)) = " << --*Poly2 << endl;
	cout << F_1 << "J(x) = Q'''(x) = d/dx(Q''(x)) = " << --*Poly2 << endl;
	cout << F_1 << "The climax of repeated operations... what a jerk!!!" <<
		endl << endl;

	// Demonstrate indefinite integration (Brown v. Board? no, the math kind)
	cout << F_1 << "First integral of J(x) = " << ++*Poly2 << endl;
	Polynomial* Poly3 = new Polynomial(*Poly2);
	cout << F_1 << "Second integral of J(x) = " << ++*Poly2 << endl;
	cout << F_1 << "Third integral of J(x) = " << ++*Poly2 << endl << endl;

	// Demonstrate definite integration
	int val = 0;
	cout << F_1 << "Define upper limit for integration: x = ";
	std::cin >> val;
	Poly3->sUpper(val);
	cout << endl;
	cout << F_1 << "Define lower limit for integration: x = ";
	std::cin >> val;
	Poly3->sLower(val);
	cout << endl << endl;

	cout << F_1 << "The definite first integration of J(x) = "
		<< (*Poly3)++ << " from x = " << Poly3->gLower() << " to x = "
		<< Poly3->gUpper() << endl << endl;

	// Demonstrate equality and inequality
	bool isEqual = *Poly0 == *Poly1;
   	bool isInequal = *Poly0 != *Poly1;

	cout << F_1 << "f(x) = g(x): " << std::boolalpha << isEqual << endl;
	cout << F_1 << "f(x) != g(x): " << std::boolalpha << isInequal << endl;

	// Demonstrate copy construction
	cout << F_1 << "F(x) = f(x)  " << endl;
	Polynomial* eqTest = new Polynomial(*Poly0);
	
	// Yep, equality and inequality totes work, yo!
	isEqual = *Poly0 == *eqTest;
   	isInequal = *Poly0 != *eqTest;

	cout << F_1 << "F(x) = f(x): " << std::boolalpha << isEqual << endl;
	cout << F_1 << "F(x) != f(x): " << std::boolalpha << isInequal
		<< std::noboolalpha << endl;

	delete Poly0;
	delete Poly1;
	delete Poly2;
	delete Poly3;
   	delete eqTest;

	return 0;
}
