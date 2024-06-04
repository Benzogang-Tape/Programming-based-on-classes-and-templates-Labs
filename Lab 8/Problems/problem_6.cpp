#include <iostream>
#include <list>


/**
	Описать функцию, которая считает количество положительных элементов заданного контейнера-списка list<int>,
	а затем распечатывает это значение (выдает в стандартный поток cout). Продемонстрировать её работу.
*/
void CountPositive(const std::list<int> &lst) {
	auto positiveCount{std::count_if(lst.cbegin(), lst.cend(), [](int n) -> bool {return n > 0;})};
	std::cout << "Total positive numbers: " << positiveCount << std::endl;
}

int main() {
	std::list<int> integers{1, -12, 54, -42, 228, 1337, -14, 2000, 98, 5};
	CountPositive(integers);
}