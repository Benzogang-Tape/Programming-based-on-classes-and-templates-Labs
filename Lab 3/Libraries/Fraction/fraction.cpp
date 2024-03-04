//
// Created by DJ Tape on 04.03.2024.
//

#include "fraction.hpp"

namespace Fraction {

	std::ostream& operator << (std::ostream &out, const Fraction& fraction) {
		out << fraction._fraction << std::endl;
		return out;
	}
}

Fraction::Fraction::Fraction(int wholePart, int numerator_i, int denominator_i, double numerator_d, double denominator_d, char* fraction)
		:_wholePart(wholePart), _numerator_i{ numerator_i }, _denominator_i{ denominator_i }, _numerator_d{ numerator_d}, _denominator_d{ denominator_d }
{
	strcpy(_fraction, fraction);
}

Fraction::Fraction::Fraction(char* fraction) {
	const char* integerPart = strstr(fraction, " ");
	if (integerPart != nullptr){
		char* intPart = (std::strtok(fraction, " "));
		int wholePart = static_cast<int>(std::strtol(intPart, nullptr, 10));
		this->_wholePart = wholePart;
	}
	char* numerator = strtok(fraction, "/");
	char* denominator = strtok(nullptr, "/");
	int num = static_cast<int>(std::strtol(numerator, nullptr, 10));
	int den = static_cast<int>(std::strtol(denominator, nullptr, 10));
	this->_numerator_i = num;
	this->_numerator_i = den;
	strcpy(_fraction, fraction);
}

void Fraction::Fraction::CreateFraction() {

}
