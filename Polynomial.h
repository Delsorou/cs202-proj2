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
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

class Polynomial
{
private:
    int deg = 0;
    int cof[9] = {};
public:
	void get_poly();
	void display_poly();
	void Add_2_Polynomials(Polynomial, Polynomial);

	Polynomial operator+(const Polynomial&);
};
#endif // POLYNOMIAL_H
