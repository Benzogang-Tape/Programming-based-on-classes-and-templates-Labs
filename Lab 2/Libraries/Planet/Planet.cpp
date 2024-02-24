//
// Created by DJ Tape on 19.02.2024.
//

#include "Planet.hpp"

size_t Planet::Planet::currentPlanetCount{};

/*
std::ostream& operator << (std::ostream &out, const Planet &planet) {
	// TODO: использовать пользовательские литералы для км и жизни
	out << planet._name << ' '
			  << planet._diameter << ' '
			  << planet._lifeExists << ' '
			  << planet._satellitesCount << std::endl;
	return out;
}
*/

void Planet::Planet::SomeFunk() {
	std::cout << "TEST" << std::endl;
}

