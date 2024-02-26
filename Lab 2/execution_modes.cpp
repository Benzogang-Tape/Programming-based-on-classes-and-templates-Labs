//
// Created by DJ Tape on 24.02.2024.
//

#include "execution_modes.hpp"

int Interactive() {
//	auto database{ std::make_unique<Road::Road[]>(7) };
//	auto database{ std::make_unique<Planet::Planet[]>(7) };
//	auto *planet = new Planet::Planet{(char*)"GogoTApe", 1488, true};
//	Database::Database<Planet::Planet> dat;
//	dat.clear();
//	dat.pushBack(planet);
	auto* planets = new Planet::Planet[12];
	while (true) {
		switch (MenuInterface::MenuInterface::Menu()) {
			case 0:
				std::cout << "Saving changes and exiting..." << std::endl;
				return 0;
			case 1:
//				std::cout << planet << std::endl;
				break;
			case 2:
				Planet::Planet::ReadDB((char *)"PlanetsDB.txt", planets);
				std::cout << "CASE 2" << std::endl;
				break;
			case 3:
//				std::cout << dat[0];
				std::cout << "CASE 3" << std::endl;
				break;
			case 4:
				delete[] planets;
				std::cout << "CASE 4" << std::endl;
				break;
			case 5:
				std::cout << "CASE 5" << std::endl;
				break;
			case 6:
				std::cout << "CASE 6" << std::endl;
				break;
			case 7:
				std::cout << "CASE 7" << std::endl;
				break;
			default:
				std::cout << "Wrong Input, pls try again." << std::endl;
				break;
		}
	}
}

int Demo() {
	auto database{ std::make_unique<Planet::Planet[]>(7) };
	std::cout << "Available options:" << std::endl;
	MenuInterface::MenuInterface::PrintOptions();
	return 0;
}
