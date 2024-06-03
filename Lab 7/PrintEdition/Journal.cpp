#include "Journal.hpp"

Journal::Journal(const char* _title, double _price) : PrintEdition::PrintEdition(_title), price(_price)
{

}

Journal::Journal(const Journal &copy) : PrintEdition::PrintEdition(copy), price(copy.price)
{

}

void Journal::print() const {
	std::cout << "Журнал: " << this->title << "	Цена: " << this->price << std::endl;
}
