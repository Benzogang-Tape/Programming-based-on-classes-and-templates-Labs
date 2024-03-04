//
// Created by DJ Tape on 04.03.2024.
//

#ifndef LABS_FRACTION_HPP
#define LABS_FRACTION_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>

namespace Fraction{

	class Fraction {
	private:
		int _wholePart{};
		int _numerator_i{};
		int _denominator_i{1};
		double _numerator_d{};
		double _denominator_d{1};
		char _fraction[54];
		void CreateFraction();

	public:
		Fraction(int = 0, int = 0, int = 1, double = 0, double = 1, char* = (char*)"0/1");

		Fraction(char* = "0/1");

		Fraction(double = 0);

		Fraction(int = 0, int = 1);

		friend std::ostream& operator << (std::ostream&, const Fraction&);

		friend std::istream& operator >> (std::istream&, Fraction&);

};
	int Demo();
	int Interactive();
}


#endif //LABS_FRACTION_HPP
