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

/* -----------------------------------------------------------------------------
FUNCTION:          main(const int, const char**)
DESCRIPTION:       There your function.
RETURNS:           int
NOTES:             None
----------------------------------------------------------------------------- */
int main(const int argc, const char* argv[])
{
    Polynomial poly[3];

    for (int n = 0; n < 2; ++n)
    {
		std::cin >> poly[n];
    }
	
	std::cout << std::right
		<< std::setw(30) << "The first polynomial is: " << poly[0] << std::endl
		<< std::setw(30) << "The second polynomial is: " << poly[1] << std::endl
		<< std::setw(30) << "Their sum is: " << poly[0] + poly[1] << std::endl;
	poly[2] = poly[0];
	poly[2] += poly[1];
	std::cout << std::setw(30) << "Compound operation: " << poly[2] << std::endl;

    return 0;
}
