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

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       There your function.
RETURNS:           int
NOTES:             None
----------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
    Polynomial poly[3];

    for (int n = 0; n < 2; ++n)
    {
		poly[n].get_poly();
		poly[n].display_poly();
    }

    poly[2] = poly[0] - poly[1];

	poly[2].display_poly();

    return 0;
}
