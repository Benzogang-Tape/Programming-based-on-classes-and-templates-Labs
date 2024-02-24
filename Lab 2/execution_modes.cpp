//
// Created by DJ Tape on 24.02.2024.
//

#include "execution_modes.hpp"

int Interactive(std::string object) {
	auto db{ std::make_unique<Road::Road[]>(7) };
	if(object == "Road"){
		auto database{ std::make_unique<Road::Road[]>(7) };
	} else
		auto database{ std::make_unique<Road::Road[]>(7) }; // Planet
	while (true) {
		switch (Abstract::AbstractObject::Menu()) {
			case 0:
				return 0;
			case 1:
				std::cout << "CASE 1" << std::endl;
				break;
			default:
				break;
		}
	}
}