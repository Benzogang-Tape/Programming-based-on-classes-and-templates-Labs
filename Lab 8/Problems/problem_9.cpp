#include <iostream>
#include <map>


void FindCompliances(std::map<std::string, std::string> &phoneBook, std::string *phoneNumbers, const size_t length) {
	for(size_t i{}; i < length; ++i) {
		if (phoneBook.count(*(phoneNumbers + i)) > 0) {
			std::cout << phoneBook[*(phoneNumbers + i)] << std::endl;
		}
	}
}


int main() {
	constexpr size_t arrSize{4};
	std::map<std::string, std::string> phoneBook{
			{"5671234", "Ivanov"},
			{"3214567", "Petrov"},
			{"9871234", "Sidorov"}
	};
	std::string phoneNumbers[arrSize] = {"1112233", "9871234", "5671234", "5556688"};

	FindCompliances(phoneBook, phoneNumbers, arrSize);
}