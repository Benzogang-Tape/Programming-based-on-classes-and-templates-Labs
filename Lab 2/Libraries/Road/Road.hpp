//
// Created by DJ Tape on 21.02.2024.
//

#ifndef LABS_ROAD_HPP
#define LABS_ROAD_HPP

#include <iostream>
#include <memory>

namespace Road {


	class Road {
		enum class RoadType {Highway = 1, Racetrack, Gravel, Mountain, Pedestrian, Hiking, Meth};
	private:
		// TODO: Add field ConstructionDate with std::chrono
		const char* _name{};
		RoadType _type{};
		unsigned _length{};
		std::string startingPoint{};
		std::string endPoint{};
		bool costFree{ true };
	public:
		static void ReadDB();
		static void WriteDB();
		static void SortDB();
		static void AddNewObject();
		static void DeleteObject();
		static void EditDB();
		static void PrintDB();
	};

//	int Menu();
	enum class Options {ReadDB = 1, WriteDB, SortBD, AddNewObject, DeleteObject, EditDB, PrintDB};
} // Road

#endif //LABS_ROAD_HPP
