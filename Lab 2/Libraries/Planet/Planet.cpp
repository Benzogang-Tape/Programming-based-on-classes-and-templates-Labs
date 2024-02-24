//
// Created by DJ Tape on 19.02.2024.
//

#include "Planet.hpp"



int Menu(bool isInteractive) {
	std::cout << "1. Print Planets \n" << "2. \n" << "3. \n" << std::endl;
	if (isInteractive) {
		int chosenOption{};
		std::cin >> chosenOption;
		return chosenOption;
	}
	return 0;
}

int Demo() {
	return Menu(false);
}

int Interactive() {
	Planet planet;
	while (int chosenOption = Menu()){
		switch (chosenOption) {
			case 1:
				std::cout << planet;
				break;
			case 2:
				std::cout << "2 works" << std::endl;
				break;
			case 3:
				planet.SomeFunk();
				std::cout << "3 works" << std::endl;
				break;
			default:
				std::cout << "Wrong input" << std::endl;
				break;
		}
	}
	return 0;
}



size_t Planet::currentPlanetCount{};

std::ostream& operator << (std::ostream &out, const Planet &planet) {
	// TODO: использовать пользовательские литералы для км и жизни
	out << planet._name << ' '
			  << planet._diameter << ' '
			  << planet._lifeExists << ' '
			  << planet._satellitesCount << std::endl;
	return out;
}


void Planet::SomeFunk() {
	std::cout << "TEST" << std::endl;
}

