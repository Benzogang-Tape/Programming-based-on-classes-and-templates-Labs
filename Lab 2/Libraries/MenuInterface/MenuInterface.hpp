//
// Created by DJ Tape on 24.02.2024.
//

#ifndef LABS_MENUINTERFACE_HPP
#define LABS_MENUINTERFACE_HPP

#include <iostream>
#include <vector>

namespace MenuInterface {

	class MenuInterface {
	private:
		static const std::vector<std::string> options;
	public:
		static const void PrintOptions();
		static const void PrintOptions(int);
		static int Menu();
	};
}

#endif //LABS_MENUINTERFACE_HPP
