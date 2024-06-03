#ifndef LAB_7_BOOK_HPP
#define LAB_7_BOOK_HPP

#include "PrintEdition.hpp"

class Book : public PrintEdition {
protected:
	char* author{};
	void setAuthor(const char *);
public:
	Book();
	Book(const Book& copy);
	explicit Book(const char*, const char*);
	void print() const override;
};


#endif //LAB_7_BOOK_HPP
