#include <iostream>


/*
	Пользователь вводит 3 строки - фамилия, имя и отчество учащегося.
	Образовать новую последовательность, оставить только фамилию и инициалы через пробел и точку.
*/
std::wstring GetSurnameWithInitials(const std::wstring &lastname, const std::wstring &firstname, const std::wstring &patronymic){
	return lastname + L" " + firstname[0] + L". " + patronymic[0] + L".";
}

int main () {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::wstring lastname{}, firstname{}, patronymic{};
	std::wcin >> lastname >> firstname >> patronymic;
	std::wcout << GetSurnameWithInitials(lastname, firstname, patronymic);
}