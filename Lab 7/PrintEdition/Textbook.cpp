#include "Textbook.hpp"

Textbook::Textbook() : Book::Book(), publicationYear(0)
{

}

Textbook::Textbook(const Textbook &copy) : Book::Book(copy), publicationYear(copy.publicationYear)
{

}

Textbook::Textbook(const char *_title, const char *_author, int _publicationYear) : Book::Book(_title, _author),
			publicationYear(_publicationYear){}

void Textbook::print() const {
	std::cout << "Учебник: " << this->title
			  << " Автор: " << this->author
			  << " Год издания: " << this->publicationYear
			  << std::endl;
}
