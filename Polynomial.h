#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

class Polynomial
{
private:
    int deg;
    int cof[9];
public:
	Polynomial();
	void get_poly();
	void display_poly();
	void Add_2_Polynomials(Polynomial, Polynomial);

	Polynomial operator+(const Polynomial&);
};
#endif // POLYNOMIAL_H
