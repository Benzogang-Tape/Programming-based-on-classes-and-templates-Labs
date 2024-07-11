#include <iostream>
#include "Planet/Planet.hpp"

int main(int argc, char *argv[]) {
//	system("chcp 1251>nul");
	bool isInteractive{}; // по умолчанию демо-режим.

	if ((argc == 2) && strcmp(argv[1], "i") == 0) {
		isInteractive = true;
	}

	if (isInteractive) {
		return demo()/*interactive()*/;
	}
	return demo();
//	return 0;
}