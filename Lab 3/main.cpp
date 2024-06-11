#include <iostream>
#include "Fraction/Fraction.hpp"

int main() {
	std::cout << "Enter the fraction: \n";
	Fraction z;
	std::cin >> z;
	if (z.getDenominator() == 0){
		std::cout << "Error: zero in denominator" << std::endl;
		return 0;
	}
	std::cout << "z=" << z << std::endl;
	// Constructors check
	Fraction fr1(10, 14), fr2;
	std::cout << "fr2=" << fr2 << std::endl;
	std::cout << "fr1=" << fr1 << std::endl;
	Fraction fr = "-1 4/8";
	std::cout << "fr=" << fr << std::endl;
	Fraction x(z), y;
	std::cout << "x=" << x << std::endl;
	double dbl = -1.25;
	Fraction f = dbl;
	std::cout << "f=" << f << std::endl;
	// Check of the overloaded operation "+"
	y = x + z;
	std::cout << "y=" << y << std::endl;
	y += x;
	f += dbl / 2;
	std::cout << "f=" << f << std::endl;
	y = x + dbl;
	std::cout << "y=" << y << std::endl;
	y = dbl + y;
	std::cout << "y=" << y << std::endl;
	y += dbl;
	std::cout << "y=" << y << std::endl;
	int i = 5;
	y += i;
	std::cout << "y=" << y << std::endl;
	y = i + x;
	std::cout << "y=" << y << std::endl;
	y = x + i;
	std::cout << "y=" << y << std::endl;
	double a = dbl + i;
	Fraction b = a + x;
	y += b;
	std::cout << "y=" << y << std::endl;
	return 0;
}
