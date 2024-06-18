#include <iostream>
#include "PrintEdition/Textbook.hpp"
#include "PrintEdition/Journal.hpp"

int main() {
	setlocale(LC_ALL, "russian");

	Journal journal("playboy", 1337);
	Book book("Drei Kameraden", "Remarque");
	Textbook textbook("Anti Demidovich", "Demidovich", 1954);

	PrintEdition::printArray();
	return 0;
}
