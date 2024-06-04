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
//	friend std::ofstream &operator<<(std::ofstream& out, const Card& card);
	[[nodiscard]] std::string getAuthor() const ;
};


#endif //LAB_8_CARD_HPP
