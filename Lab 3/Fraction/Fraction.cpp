#include "Fraction.hpp"

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator)
{
	toIrreducible();
}

Fraction::Fraction(double num)
{
	denominator = 1;
	int temp = countDigits(num);
	numerator = num * pow(10, temp);
	denominator *= pow(10, temp);
	toIrreducible();
}

Fraction::Fraction(char* num)
{
	int fullPart;
	char* pEnd, *pch, *temp;
	pch = std::strchr(num, '/');
	temp = std::strchr(num, ' ');
	// with whole part
	if (temp != nullptr) {
		fullPart = strtol(num, &pEnd, 10);
		numerator = strtol(pEnd, &pch, 10);
		denominator = strtol(pch + 1, nullptr, 10);
		if ((fullPart < 0) || (num[0] == '-'))
			numerator *= -1;
		numerator += fullPart * denominator;
	}
	// without fractional part
	else if (pch == nullptr) {
		numerator = strtol(num, nullptr, 10);
		denominator = 1;
	}
	// only fraction
	else {
		numerator = strtol(num, &pch, 10);
		denominator = strtol(pch + 1, nullptr, 10);
	}
	toIrreducible();
}

void Fraction::toIrreducible()
{
	if (this->denominator != 0 and this->numerator != 0) {
		int nod = NOD(abs(this->numerator), abs(this->denominator));
		this->numerator /= nod;
		this->denominator /= nod;
	}

}

int Fraction::getDenominator()
{
	return this->denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	if (fraction.denominator == 1 && fraction.numerator != 0)
		out << fraction.numerator;
	else if (fraction.numerator == 0)
		out << 0;
	else if (fraction.denominator == 0)
		std::cout << "Error: zero in denominator" << std::endl;
	else {
		if (abs(fraction.numerator) > fraction.denominator)
			std::cout << fraction.numerator / fraction.denominator << ' ' << abs(fraction.numerator) % fraction.denominator << '/' << fraction.denominator;
		else
			out << fraction.numerator << '/' << fraction.denominator;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
	char* line = new char[60];
	std::cin.getline(line, 60, '\n');
	fraction = Fraction(line);
	return in;
}

//Fraction operator+(Fraction& lhs, Fraction& rhs)
//{
//	rhs.toIrreducible();
//	lhs.toIrreducible();
//	int nok = NOK(lhs.denominator, rhs.denominator);
//	Fraction result((nok / lhs.denominator) * lhs.numerator + (nok / rhs.denominator) * rhs.numerator, nok);
//	result.toIrreducible();
//	return result;
//}

Fraction Fraction::operator+(Fraction &rhs) {
	int nok = NOK(denominator, rhs.denominator);
	Fraction result((nok / denominator) * numerator + (nok / rhs.denominator) * rhs.numerator, nok);
	result.toIrreducible();
	return result;
}

Fraction operator+(Fraction& lhs,const int rhs)
{
	Fraction result(lhs.numerator + rhs * lhs.denominator, lhs.denominator);
	result.toIrreducible();
	return result;
}

Fraction operator+(const int lhs, Fraction& rhs)
{
	Fraction result(rhs.numerator + lhs * rhs.denominator, rhs.denominator);
	result.toIrreducible();
	return result;
}

Fraction operator+=(Fraction& lhs, Fraction& rhs)
{
	lhs = rhs + lhs;
	lhs.toIrreducible();
	return lhs;
}

Fraction operator+=(Fraction& lhs, const int rhs)
{
	lhs.numerator += rhs * lhs.denominator;
	lhs.toIrreducible();
	return lhs;
}

Fraction operator+(Fraction& lhs, const double rhs)
{
	Fraction result(rhs);
	result += lhs;
	result.toIrreducible();
	return result;
}

Fraction operator+(const double lhs, Fraction& rhs)
{
	Fraction result(lhs);
	result += rhs;
	result.toIrreducible();
	return result;
}

Fraction operator+=(Fraction& lhs, const double rhs)
{
	lhs = lhs + rhs;
	lhs.toIrreducible();
	return lhs;
}

int countDigits(double num)
{
	int count = 0;
	while (num != int(num)) {
		num *= 10;
		count++;
	}
	return count;
}

int NOD(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}
	while (a % b != 0) {
		a = a % b;
		std::swap(a, b);
	}
	return b;
}

int NOK(int a, int b)
{
	return a * b / NOD(a, b);
}