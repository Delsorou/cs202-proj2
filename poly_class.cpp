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
#define F_2 setw(15)

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

    Polynomial poly[3];

    for (int n = 0; n < 2; ++n)
    {
		std::cin >> poly[n];
    }

	cout << std::right
		<< F_1 << "The first polynomial is: " << F_2 << poly[0] << endl
		<< F_1 << "The second polynomial is: " << F_2 << poly[1] << endl
		<< endl;

	// Demonstrate addition and compound addition assignment
	cout << F_1 << "Their sum is: " << F_2 << poly[0] + poly[1] << endl;
	poly[2] = poly[0];
	poly[2] += poly[1];
	cout << F_1 << "Compound operation: " << F_2 << poly[2] << endl	<< endl;

	// Demonstrate subtraction and compound subtraction assignment
	cout << F_1 << "Their difference is: " << F_2 << poly[0] - poly[1]
		<< endl;
	poly[2] = poly[0];
	poly[2] -= poly[1];
	cout << F_1 << "Compound operation: " << F_2 << poly[2] << endl	<< endl;

	// Demonstrate multiplication and compound multiplication assignment
	cout << F_1 << "Their product is: " << F_2 << poly[0] * poly[1]
		<< endl;
	poly[2] = poly[0];
	poly[2] *= poly[1];
	cout << F_1 << "Compound operation: " << F_2 << poly[2] << endl	<< endl;

    return 0;
}
