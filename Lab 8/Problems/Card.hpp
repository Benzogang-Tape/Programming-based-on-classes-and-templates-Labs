#ifndef LAB_8_CARD_HPP
#define LAB_8_CARD_HPP


#include <iostream>

class Card {
private:
	std::string title;
	std::string author;
	int number{};
public:
	Card();
	Card(std::string, std::string, int);
	void print() const;
	[[nodiscard]] std::string getAuthor() const ;
};


#endif //LAB_8_CARD_HPP
