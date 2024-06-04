#include <iostream>
#include <fstream>
#include <string>

/**
	Дан текстовый файл. Запишите в другой файл содержимое исходного файла, утроив восклицательный знак.
*/
void DecorateText(std::ifstream &in, std::ofstream &out) {
	std::string line{};
	while (getline(in, line)) {
		size_t pos = 0;
		while ((pos = line.find('!', pos)) != std::string::npos) {
			line.replace(pos, 1, "!!!");
			pos += 3;
		}
		out << line << std::endl;
	}
}


int main() {
	std::ifstream inputFile("../../Resources/problem_3.txt");
	std::ofstream outputFile("../../Resources/problem_3_out.txt");

	if (!inputFile.is_open()) {
		std::cout << "Error opening file by path: ../../Resources/problem_3.txt" << std::endl;
		return 1;
	}
	if (!outputFile.is_open()) {
		std::cout << "Error opening file by path: ../../Resources/problem_3_out.txt" << std::endl;
		return 1;
	}

	DecorateText(inputFile, outputFile);

	inputFile.close();
	outputFile.close();

	std::cout << "Done" << std::endl;
	return 0;
}