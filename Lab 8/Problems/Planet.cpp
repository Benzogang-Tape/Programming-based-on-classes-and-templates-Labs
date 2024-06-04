#include "Planet.hpp"

#include <utility>

Planet::Planet() = default;

Planet::Planet(std::string _name, const size_t _satelliteCount) :
	name(std::move(_name)), satelliteCount(_satelliteCount)
	{

	}

std::string Planet::getName() const {
	return name;
}

size_t Planet::getSatelliteCount() const {
	return satelliteCount;
}

void Planet::setName(const std::string &newName) {
	this->name = newName;
}

void Planet::setSatelliteCount(const size_t newSatelliteCount) {
	this->satelliteCount = newSatelliteCount;
}
