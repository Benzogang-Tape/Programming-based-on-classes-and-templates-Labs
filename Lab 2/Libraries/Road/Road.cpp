//
// Created by DJ Tape on 21.02.2024.
//

#include "Road.hpp"
#include <iostream>
#include <memory>

namespace Road {


} // Road

int Road::Menu() {
	std::cout <<"\nWhat do you want to do? Choose from the options below:" << std::endl;
	std::cout << MenuInterface;
	while (true) {
		std::cout << "Enter your choice: ";
		int chosenOption{};
		std::cin >> chosenOption;
		if (0 <= chosenOption and chosenOption <= 7) {
			return chosenOption;
		}
		std::cout << "\nWrong input. Please read available actions and try again.\n";
	}
}

int Road::Interactive() {
	auto roads{ std::make_unique<Road[]>(7) };
	while (true) {
		switch (Menu()) {
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