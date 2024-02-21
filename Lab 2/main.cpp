#include <iostream>
#include <Planet.hpp>
#include <Road.hpp>

int main(int argc, char* argv[]) {
	bool isInteractive{};
	if (argc == 2 and strcmp(argv[1], "i") == 0) {
		isInteractive = true;
	}
	if(isInteractive){
		return IsInteractive();
	}
	return Demo();
}
