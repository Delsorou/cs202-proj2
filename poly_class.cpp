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
		std::cout << std::endl << poly[n];
    }
	
	std::cout << std::endl << std::boolalpha << (poly[0] == poly[1]) << std::endl;

    return 0;
}
