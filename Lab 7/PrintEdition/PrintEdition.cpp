#include "PrintEdition.hpp"


MyVector<PrintEdition*> PrintEdition::edits;

PrintEdition::PrintEdition() : title(const_cast<char *>("")){}

PrintEdition::PrintEdition(const PrintEdition& edition) : title(edition.title) { edits.addElement(this); }

PrintEdition::PrintEdition(const char* _title) {
	setTitle(_title);
	addEdition(this);
}

PrintEdition::~PrintEdition() = default;

void PrintEdition::setTitle(const char* newTitle) {
	auto size = std::strlen(newTitle) + 1;
	this->title = new char[size];
	std::strncpy(this->title, newTitle, size);
}

void PrintEdition::addEdition(PrintEdition *edition) { // static
	edits.addElement(edition);
}

void PrintEdition::print() const {
	std::cout << "Печатное издание: " << this->title << std::endl;
}

void PrintEdition::printArray() {
	for (int i = 0; i < edits.getSize(); i++) {
		edits[i]->print();
	}
}