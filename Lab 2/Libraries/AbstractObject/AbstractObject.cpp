//
// Created by DJ Tape on 23.02.2024.
//

#include "AbstractObject.hpp"

const std::string Abstract::AbstractObject::MenuInterface{ "1. Read from Database\n"
														   "2. Save to Database\n"
														   "3. Sort Database\n"
														   "4. Add a new record to the database\n"
														   "5. Delete a record from the Database\n"
														   "6. Edit Database\n"
														   "7. Print Database\n"
														   "------------------------------------\n"
														   "0. Exit\n" };
int Abstract::AbstractObject::Menu() {
	std::cout <<"\nWhat do you want to do? Choose from the options below:" << std::endl;
	PrintAvailableActions();
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

void Abstract::AbstractObject::PrintAvailableActions() {
	std::cout << MenuInterface;
}
