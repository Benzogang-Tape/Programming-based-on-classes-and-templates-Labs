#include "Card.hpp"
#include <utility>

Card::Card() = default;

Card::Card(std::string _title, std::string _author, const int _number) :
		title(std::move(_title)), author(std::move(_author)), number(_number)
		{

		}

void Card::print() const {
	std::cout << "Название: " << title << std::endl;
	std::cout << "Автор: " << author << std::endl;
	std::cout << "Количество экземпляров: " << number << std::endl;
	std::cout << "--------------------------" << std::endl;
}

std::string Card::getAuthor() const {
	return author;
}

/*
std::ofstream &operator<<(std::ofstream &out, const Card& card) {
	out << const_cast<char *>("Название: ") << card.title << std::endl;
	out << "Автор: " << card.author << std::endl;
	out << "Количество экземпляров: " << card.number << std::endl;
	out << "--------------------------" << std::endl;
	return out;
}
*/

