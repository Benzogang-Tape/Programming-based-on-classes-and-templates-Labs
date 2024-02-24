//
// Created by DJ Tape on 19.02.2024.
//

#ifndef LABS_PLANET_HPP
#define LABS_PLANET_HPP

#include <iostream>
#include <cstring>
namespace Planet {

	class Planet {
	private:
		static size_t currentPlanetCount;
		size_t _id{};
		const char *_name = "PLANETA";
		unsigned _diameter{};
		bool _lifeExists{};
		unsigned _satellitesCount{};
	public:
		friend std::ostream& operator << (std::ostream&, const Planet&);
		void SomeFunk();
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
