//
// Created by DJ Tape on 21.02.2024.
//

#ifndef LABS_ROAD_HPP
#define LABS_ROAD_HPP

#include <iostream>
#include <memory>
#include <../AbstractObject/AbstractObject.hpp>

namespace Road {


	class Road : public Abstract::AbstractObject{
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
		void ReadDB() override;
		void WriteDB() override;
		void SortDB() override;
		void AddNewObject() override;
		void DeleteObject() override;
		void EditDB() override;
		void PrintDB() override;
	};

//	int Menu();
	enum class Options {ReadDB = 1, WriteDB, SortBD, AddNewObject, DeleteObject, EditDB, PrintDB};
} // Road

#endif //LABS_ROAD_HPP
