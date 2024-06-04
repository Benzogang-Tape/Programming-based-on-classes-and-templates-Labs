#include <iostream>
#include <map>


void PrintMap(const std::map<int, double> &map) {
	for (const auto& [integer, decimal] : map) {
		std::cout << integer << ": " << decimal << std::endl;
	}
	std::cout << std::endl;
}

/**
	Создайте отображение map<int, double> и занесите в него пары 1 - 1.1, 2 - 2.2, 3 - 3.3, 4 - 4.4, 5 - 5.5, ..., 9 - 9.9.
	Выведите содержимое отображения на экран. Удалить пары с четными ключами и снова распечатайте отображение.
*/
void DeleteEven(std::map<int, double> &map) {
	for (auto& [key, value] : map) {
		if (!(key % 2)) {
			map.erase(key);
		}
	}
}

int main() {
	std::map<int, double> map {
			{1, 1.1},
			{2, 2.2},
			{3, 3.3},
			{4, 4.4},
			{5, 5.5},
			{6, 6.6},
			{7, 7.7},
			{8, 8.8},
			{9, 9.9},
	};
	PrintMap(map);
	DeleteEven(map);
	PrintMap(map);
}