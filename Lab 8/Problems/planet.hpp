#ifndef LAB_8_PROBLEM_5_HPP
#define LAB_8_PROBLEM_5_HPP


#include <iostream>

class Planet {
private:
	std::string name{"DEFAULT_PLANET"};
	size_t satelliteCount{};
public:
	Planet();
	Planet(std::string  _name, size_t _satelliteCount);
	[[nodiscard]] std::string getName() const;
	[[nodiscard]] size_t getSatelliteCount() const;
	void setName(const std::string &newName);
	void setSatelliteCount(size_t newSatelliteCount=0);
};


#endif //LAB_8_PROBLEM_5_HPP
