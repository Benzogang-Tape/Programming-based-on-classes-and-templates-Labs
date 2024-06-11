#ifndef LAB_3_FRACTION_HPP
#define LAB_3_FRACTION_HPP

#include <iostream>
#include <iomanip>
#include <locale>
#include <cmath>
#include <cstring>


static int N_DEC = 4;

class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int, int);
	Fraction(double);
	Fraction(char*);

	friend std::ostream& operator << (std::ostream&, const Fraction&);
	friend std::istream& operator >> (std::istream&, Fraction&);
	friend Fraction operator + (Fraction&, Fraction&);
//	Fraction operator + (Fraction&);
	friend Fraction operator + (Fraction&, int);
	friend Fraction operator + (int, Fraction&);
	friend Fraction operator += (Fraction&, Fraction&);
	friend Fraction operator += (Fraction&, int);
	friend Fraction operator + (Fraction&, double);
	friend Fraction operator + (double, Fraction&);
	friend Fraction operator += (Fraction&, double);
	void toIrreducible();
	int getDenominator();
};

int countDigits(double);
int NOD(int, int);
int NOK(int, int);


#endif //LAB_3_FRACTION_HPP
