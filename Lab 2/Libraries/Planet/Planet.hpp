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

		~Planet();

		friend std::ostream& operator << (std::ostream&, const Planet&);

		friend std::istream& operator >> (std::istream&, Planet&);

		static void ReadDB(char *, Planet *);

		static void WriteDB();

		static void SortDB();

		static void AddNewObject();

		static void DeleteObject();

		static void EditDB();

		static void PrintDB();

		[[nodiscard]] size_t GetId() const;

		[[nodiscard]] const char *GetName() const;

		[[nodiscard]] unsigned int GetDiameter() const;

		[[nodiscard]] unsigned int GetSatellitesCount() const;

		[[nodiscard]] bool IsLifeExists() const;

		void SetName(const char* name);

		void SetDiameter(unsigned int diameter);

		void SetLifeExists(bool lifeExists);

		void SetSatellitesCount(unsigned int satellitesCount);
	};

}

#endif //LABS_PLANET_HPP
