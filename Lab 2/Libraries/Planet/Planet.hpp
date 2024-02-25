//
// Created by DJ Tape on 19.02.2024.
//

#ifndef LABS_PLANET_HPP
#define LABS_PLANET_HPP

#include <iostream>
#include <cstring>
#include <fstream>

namespace Planet {

	class Planet {
	private:
		static size_t currentPlanetCount;
		size_t _id{};
		char _name[256]{ "DEFAULT_PLANET" };
		unsigned _diameter{};
		bool _lifeExists{};
		unsigned _satellitesCount{};
	public:
		explicit Planet(const char* = (char*)"DEFAULT_PLANET", unsigned = 0, bool = false, unsigned = 0);
		friend std::ostream& operator << (std::ostream&, const Planet&);
		friend std::istream& operator >> (std::istream&, Planet&);
		static void ReadDB();
		static void WriteDB();
		static void SortDB();
		static void AddNewObject();
		static void DeleteObject();
		static void EditDB();
		static void PrintDB();
	};

}

#endif //LABS_PLANET_HPP
