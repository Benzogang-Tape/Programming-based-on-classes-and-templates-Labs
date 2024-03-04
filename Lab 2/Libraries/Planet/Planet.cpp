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


void Planet::Planet::Read(char* file, Database::Database<Planet> &db) {
	std::ifstream database(file);
	if (!database) {
		std::cout << "Unable to read file.";
		return;
	}
//	size_t counter{};
	size_t amountOfRecords{static_cast<size_t>(std::count(std::istreambuf_iterator<char>(database), {}, '\n') + 1)};
//	std::cout << "AMOUNT OF LINES: " << amountOfRecords << std::endl;
	if (db.getCapacity() < amountOfRecords) {
		db.Resize(amountOfRecords);
	}
	database.seekg(std::ios::beg);
	for (size_t i{}; i < amountOfRecords; ++i) {
		database >> db[i];
	}
	database.close();
//	while (database) {
//		Planet pl{};
//		database >> pl;
////		db.pushBack1(pl);
//		db[counter] = pl;
//		counter++;
//		if (database.eof()) {
//			database.close();
//			break;
//		}
//	}
	std::cout << "Data successfully fetched!" << std::endl;
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

Planet::Planet &Planet::Planet::operator= (const Planet& planet) {
	if (this == &planet)
		return *this;
	strcpy(this->_name, planet._name);
	this->_diameter = planet._diameter;
	this->_lifeExists = planet._lifeExists;
	this->_satellitesCount = planet._satellitesCount;

	return *this;
}

void Planet::Planet::PrintDB(Database::Database<Planet> &database) {
	for (size_t i{}; i < database.getSize(); ++i) {
		if (!strcmp(database[i].GetName(), "DEFAULT_PLANET")) {
			if (!i) {
				std::cout << "Current Planet's list is empty.\nYou can refresh it by fetching data from DB" << std::endl;
			}
			break;
		}
		std::cout << i + 1 << ") " << database[i];
	}
}

















//	template <typename Stream>
//	void test(Stream &stream) {
//		stream << std::showpoint << std::fixed << std::right;
//	}