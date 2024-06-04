#include <iostream>
#include <vector>
#include <iomanip>
#include "Planet.hpp"


void PrintPlanets(const std::vector<Planet> &planets) {
	std::pair<std::string, size_t> maxSatelliteCount{};
	for (const auto &planet : planets) {
		if (maxSatelliteCount.second < planet.getSatelliteCount()) {
			maxSatelliteCount.first = planet.getName();
			maxSatelliteCount.second = planet.getSatelliteCount();
		}
		std::cout << std::quoted(planet.getName()) << " " << planet.getSatelliteCount() << std::endl;
	}
	std::cout << std::endl << "Больше всего спутников: " << maxSatelliteCount.first << " - " << maxSatelliteCount.second << std::endl;
}


int main() {
	std::vector<Planet> planets(9);
	planets[0].setName("Меркурий");
	planets[0].setSatelliteCount();
	planets[1].setName("Венера");
	planets[1].setSatelliteCount();
	planets[2].setName("Земля");
	planets[2].setSatelliteCount(1);
	planets[3].setName("Марс");
	planets[3].setSatelliteCount(2);
	planets[4].setName("Юпитер");
	planets[4].setSatelliteCount(69);
	planets[5].setName("Сатурн");
	planets[5].setSatelliteCount(62);
	planets[6].setName("Уран");
	planets[6].setSatelliteCount(27);
	planets[7].setName("Нептун");
	planets[7].setSatelliteCount(14);
	planets[8].setName("Плутон");
	planets[8].setSatelliteCount(10);
	PrintPlanets(planets);
}