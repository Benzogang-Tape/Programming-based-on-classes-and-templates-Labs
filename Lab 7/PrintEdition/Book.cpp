#include "Book.hpp"


Book::Book() : PrintEdition::PrintEdition(), author(const_cast<char *>(""))
{

}

Book::Book(const char* _title, const char* _author) : PrintEdition::PrintEdition(_title)
{
	setAuthor(_author);
}

Book::Book(const Book &copy) : PrintEdition::PrintEdition(copy), author(copy.author)
{

}

void Book::setAuthor(const char* newAuthor) {
	auto size = std::strlen(newAuthor) + 1;
	this->author = new char[size];
	std::strncpy(this->author, newAuthor, size);
}

void Book::print() const {
	std::cout << "Книга: " << this->title
			  << " Автор: " << this->author
			  << std::endl;
}
