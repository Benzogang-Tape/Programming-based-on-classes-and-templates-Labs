//
// Created by DJ Tape on 24.02.2024.
//

#include "MenuInterface.hpp"

const std::vector<std::string>MenuInterface::MenuInterface::options{"0. Exit\n",
																	"1. Read from Database\n",
																	"2. Save to Database\n",
																	"3. Sort Database\n",
																	"4. Add a new record to the database\n",
																	"5. Delete a record from the Database\n",
																	"6. Edit Database\n",
																	"7. Print Database\n"};

const void MenuInterface::MenuInterface::PrintOptions() {
	for(auto i = options.cbegin() + 1; i != options.cend(); ++i) {
		std::cout << *i;
	}
}

const void MenuInterface::MenuInterface::PrintOptions(int option) {
	if (option < 1 or 7 < option) {
		std::cout << "That option doesn't exist" << std::endl;
		return;
	}
	std::cout << options[option];
}

int MenuInterface::MenuInterface::Menu() {
	std::cout <<"\nWhat do you want to do? Choose from the options below:\n" << std::endl;
	PrintOptions();
	std::cout << "------------------------------------\n" << options[0];
	while (true) {
		std::cout << "\nEnter your choice: ";
		int chosenOption{};
		std::cin >> chosenOption;
		if (0 <= chosenOption and chosenOption <= 7) {
			std::cout << std::endl;
			return chosenOption;
		}
		std::cout << "\nWrong input. Please read available actions and try again.\n";
	}
}
