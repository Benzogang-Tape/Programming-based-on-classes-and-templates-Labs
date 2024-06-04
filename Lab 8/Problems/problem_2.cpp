#include <iostream>


/**
	Пользователь вводит 2 слова в 2-х разных переменных одинаковой длины.
	Образовать новую последовательность, в которой должны чередоваться буквы первого и второго слова.
*/
std::wstring NewSequence(const std::wstring &first, const std::wstring &second) {
	if (first.length() != second.length()) {
		return L"The words must be the same length";
	}
	std::wstring result{};
	for (size_t i{}; i < first.length(); ++i) {
		result += first[i];
		result += second[i];
	}
	return result;
}

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::wstring firstWord{}, secondWord{};
	std::wcin >> firstWord >> secondWord;
	std::wcout << NewSequence(firstWord, secondWord);
}