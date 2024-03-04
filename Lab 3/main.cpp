//
// Created by DJ Tape on 04.03.2024.
//
#include <iostream>
#include <fraction.hpp>

int main() {
	char y[] = "1/2";
	Fraction::Fraction fr(y);
	std::cout << fr;
	return 0;
}