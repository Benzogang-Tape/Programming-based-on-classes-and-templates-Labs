#include <iostream>
#include <list>
#include "Card.hpp"


void PrintCards(const std::list<Card> &cards) {
	for (const auto &card : cards) {
		card.print();
	}
}

void PrintCardsByAuthor(const std::list<Card> &cards, const std::string& author) {
	bool found{};
	for (const auto &card : cards) {
		if (card.getAuthor() == author) {
			found = true;
			card.print();
		}
	}
	if (!found) {
		std::cout << "Книг от данного автора не найдено" << std::endl;
	}
}

int main() {
	std::list<Card> cards{};
	cards.emplace_back("Война и мир", "Толстой", 1);
	cards.emplace_back("Drei Cameraden", "Remarque", 2);
	cards.emplace_back("Мастер и Маргарита", "Булгаков", 3);
	cards.emplace_back("Герой нашего времени", "Лермонтов", 4);
	cards.emplace_back("Повести Белкина", "Пушкин", 5);
	PrintCards(cards);
	std::string authorToFind{};
	std::cout << "\nВведите автора для поиска: ";
	std::cin >> authorToFind;
	PrintCardsByAuthor(cards, authorToFind);
}