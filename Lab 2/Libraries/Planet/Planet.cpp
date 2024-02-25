//
// Created by DJ Tape on 19.02.2024.
//

#include "Planet.hpp"

size_t Planet::Planet::currentPlanetCount{};

namespace Planet {

	std::ostream& operator << (std::ostream &out, const Planet &planet) {
		// TODO: использовать пользовательские литералы для км и жизни
		out << planet._name << ' '
			<< planet._diameter << ' '
			<< planet._lifeExists << ' '
			<< planet._satellitesCount << std::endl;
		return out;
	}

	std::istream& operator >> (std::istream &in, Planet &planet) {
		in >> planet._name >> planet._diameter >> planet._lifeExists >> planet._satellitesCount;
		return in;
	}

}

Planet::Planet::Planet(const char name[], unsigned diameter, bool lifeExists, unsigned satellitesCount)
					: _diameter{ diameter }, _lifeExists{ lifeExists }, _satellitesCount{ satellitesCount }
{
	strcpy(_name, name);
	currentPlanetCount++;
	this -> _id = currentPlanetCount;
	std::cout << "Creating ID " << _id << std::endl;
}

void Planet::Planet::ReadDB() {
	std::ifstream database("PlanetsDB.txt");
	if (!database) {
		std::cout << "Unable to read file.";
	}
	while (database) {
		Planet pl{};
		database >> pl;
		std::cout << pl;
	}
	database.close();
}












//	template <typename Stream>
//	void test(Stream &stream) {
//		stream << std::showpoint << std::fixed << std::right;
//	}