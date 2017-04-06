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

#define F_1 setw(30)

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
	cout << F_1 << "(f * g)(x) = " << *Poly0 * *Poly1 << endl;
	*Poly2 = *Poly0;
	*Poly2 *= *Poly1;
	cout << F_1 << "(using *=): " << *Poly2 << endl << endl;

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
		<< std::noboolalpha << endl << endl;

	// Demonstrate evaluation
	cout << F_1 << "Please define: x = ";
	int value = 0;
	std::cin >> value;
	cout << endl << endl;

	cout << F_1 << "f(x) = " << (*Poly0)(value) << " at x = " << value << endl;
	cout << F_1 << "g(x) = " << (*Poly1)(value) << " at x = " << value << endl;

	delete Poly0;
	delete Poly1;
	delete Poly2;
   	delete eqTest;

	return 0;
}
