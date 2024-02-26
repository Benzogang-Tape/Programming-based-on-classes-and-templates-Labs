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
		char name[256]{};
		unsigned diameter{}, satellitesCount{};
		bool lifeExists{};
		in >> name >> diameter >> lifeExists >> satellitesCount;
		planet.SetName(name);
		planet.SetDiameter(diameter);
		planet.SetLifeExists(lifeExists);
		planet.SetSatellitesCount(satellitesCount);
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

void Planet::Planet::ReadDB(char* file, Planet* planets) {
	std::ifstream database(file);
	if (!database) {
		std::cout << "Unable to read file.";
		return;
	}
	size_t counter{};
	while (database) {
		auto* planet = new Planet{};
		database >> *planet;
		std::cout << *planet;
		planets[counter] = *planet;
		counter++;
		if (database.eof()) {
			database.close();
			break;
		}
	}
}

size_t Planet::Planet::GetId() const {
	return _id;
}

const char *Planet::Planet::GetName() const {
	return _name;
}

unsigned int Planet::Planet::GetDiameter() const {
	return _diameter;
}

bool Planet::Planet::IsLifeExists() const {
	return _lifeExists;
}

unsigned int Planet::Planet::GetSatellitesCount() const {
	return _satellitesCount;
}

void Planet::Planet::SetName(const char *name) {
	std::strcpy(_name, name);
}

void Planet::Planet::SetDiameter(unsigned int diameter) {
	_diameter = diameter;
}

void Planet::Planet::SetSatellitesCount(unsigned int satellitesCount) {
	_satellitesCount = satellitesCount;
}

void Planet::Planet::SetLifeExists(bool lifeExists) {
	_lifeExists = lifeExists;
}

Planet::Planet::~Planet() {
	currentPlanetCount--;
	std::cout << "Deleting ID" << _id << std::endl;
}















//	template <typename Stream>
//	void test(Stream &stream) {
//		stream << std::showpoint << std::fixed << std::right;
//	}