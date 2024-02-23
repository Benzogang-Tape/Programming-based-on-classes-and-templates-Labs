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
void Abstract::AbstractObject::Menu() {
	std::cout << MenuInterface;
}