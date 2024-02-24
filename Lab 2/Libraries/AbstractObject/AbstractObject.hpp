//
// Created by DJ Tape on 23.02.2024.
//

#ifndef LABS_ABSTRACTOBJECT_HPP
#define LABS_ABSTRACTOBJECT_HPP

#include <iostream>

namespace Abstract {

	class AbstractObject {
	private:
		static const std::string MenuInterface;
	public:
		static void PrintAvailableActions();
		static int Menu();
		virtual void ReadDB() = 0;
		virtual void WriteDB() = 0;
		virtual void SortDB() = 0;
		virtual void AddNewObject() = 0;
		virtual void DeleteObject() = 0;
		virtual void EditDB() = 0;
		virtual void PrintDB() = 0;
	};
	//TODO: Add const keyword to the related functions
} // Abstract

#endif //LABS_ABSTRACTOBJECT_HPP
