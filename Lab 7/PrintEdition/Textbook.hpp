#ifndef LAB_7_TEXTBOOK_HPP
#define LAB_7_TEXTBOOK_HPP


#include "Book.hpp"


class Textbook : public Book {
protected:
	int publicationYear{};
public:
	Textbook();
	Textbook(const Textbook& copy);
	explicit Textbook(const char*, const char*, int);
	void print() const override;
};


#endif //LAB_7_TEXTBOOK_HPP
