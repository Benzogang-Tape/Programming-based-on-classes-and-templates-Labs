#ifndef LAB_7_PRINTEDITION_HPP
#define LAB_7_PRINTEDITION_HPP

#include "../../Lab 5.2/MyContainers/MyVector.hpp"

class PrintEdition {
protected:
	char* title{};
	static MyVector<PrintEdition *> edits;
	void setTitle(const char*);
public:
	PrintEdition();
	PrintEdition(const PrintEdition&);
	explicit PrintEdition(const char*);
	void addEdition(PrintEdition*);
	//void deleteDocument();
	virtual ~PrintEdition();
	virtual void print() const;
	static void printArray();
};


#endif //LAB_7_PRINTEDITION_HPP
