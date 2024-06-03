#ifndef LAB_7_JOURNAL_HPP
#define LAB_7_JOURNAL_HPP


#include "PrintEdition.hpp"

class Journal : virtual public PrintEdition {
protected:
	double price{};
public:
	Journal() : PrintEdition::PrintEdition(), price(0) {};
	Journal(const Journal& copy);
	explicit Journal(const char*, double);
	void print() const override;
};


#endif //LAB_7_JOURNAL_HPP
