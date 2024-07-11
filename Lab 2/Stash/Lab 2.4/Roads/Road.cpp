//
// Created by DJ Tape on 06.06.2024.
//

#include "Road.hpp"

Ticket::Ticket(){
	total++;
	id = total;
	//std::cout << "Создание ID" << id << std::endl;
	Person = new char [1];
	Person[0] = '\0';
	Time = 0;
	Price = 0;
	Baggage = 0;
}
Ticket::Ticket(const Ticket& arr){
	Person = new char [std::strlen(arr.Person) + 1];
	std::strncpy(Person, arr.Person, std::strlen(arr.Person) + 1);
	Time = arr.Time;
	Price = arr.Price;
	Baggage = arr.Baggage;
}
Ticket::Ticket(const char* Person, int Time, int Price, int Baggage){
	this->Person= new char [std::strlen(Person)+1];
	std::strcpy(this->Person, Person);
	this->Time=Time;
	this->Price=Price;
	this->Baggage=Baggage;
}
int Ticket::read_db(const char* filename, Ticket* arr, int &n) {
	std::ifstream fin(filename, std::ios::in | std::ios::binary);
	if (!fin){
		std::cout<<"Файла " << filename << " нет!" << std::endl;
		return 1;
	}
	fin >> n;
	for (int i = 0; i < n; i++){
		fin >> arr[i];
	}
	fin.close();
	return 0;
}
int Ticket::write_db(const char* filename, const Ticket* arr, int n){
	std::ofstream fin(filename, std::ios::out);
	if (!fin){
		std::cout<<"Файла " << filename << " нет!" << std::endl;
		return 1;
	}
	fin << n << std::endl;
	for (int i=0; i<n; i++){
		fin << arr[i];
	}
	fin.close();
	return 0;
}
void Ticket::sort_db(Ticket* arr, int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j] < arr[j + 1]){
				Ticket temp{arr[j]};
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
Ticket* Ticket::delete_word(Ticket* arr, int &n, int &N, bool IsInteractive){
	int count = 0, n1 = n;
	if (n - 1 < int(N/4)){
		N = N/2;
		std::cout << "Размер массива избыточен, поэтому уменьшен вдвое" << '\n';
	}
	Ticket* newArr = new Ticket[N];
	for(int i = 0; i < n; i++){
		newArr[i] = arr[i];
	}
	char* word = new char [20];
	std::cout << "Введите слово для удаления:" << '\n';
	std::cin >> word;
	for (int i = 0; i < n; i++){
		if(!strcmp(word, newArr[i].Person)){
			if (i != n - 1){
				for (int j = i; j < n - 1; j++){
					newArr[j] = newArr[j + 1];
				}
			}
			else{
				count--;
			}
			n--;
		}
		count++;
	}
	delete[] word;
	if (count == n1){
		std::cout << "Такого слова в словаре нет!" << std::endl;
	}
	delete[] arr;
	return newArr;
}
void Ticket::print_db(const Ticket* arr, int n){
	for (int i = 0; i < n; i++){
		std::cout << arr[i];
	}
	std::cout << std::endl;
}
Ticket* Ticket::add_word(Ticket* arr, int &n, int &N, bool IsInteractive){
	if (n + 1 > N){
		N = N * 2;
		std::cout << "Достигнут предел базы данных! Размер увеличен вдвое!" << '\n';
	}
	Ticket* newArr = new Ticket[N];
	for(int i = 0; i < n; i++){
		newArr[i] = arr[i];
	}
	n++;
	Ticket newStruct;
	std::cout << "Введите данные о пассажире" << '\n';
	std::cin >> newStruct;
	newArr[n-1] = newStruct;
	delete[] arr;
	return newArr;
}
void Ticket::change_value(Ticket* arr, int n, bool IsInteractive){
	Ticket ticket;
	if (IsInteractive){
		std::cout << "Выберите имя человека для редактирования:" << '\n';
		std::cin >> ticket.Person;
		for(int i = 0; i < n; i++){
			if(ticket == arr[i]){
				int num;
				std::cout << "Выберите параметр редактирования:" << '\n';
				std::cout << "1. Изменить имя пассажира" << '\n';
				std::cout << "2. Изменить время поездки" << '\n';
				std::cout << "3. Изменить стоимость билета" << '\n';
				std::cout << "4. Изменить кол-во багажа" << '\n';
				std::cin >> num;
				switch (num){
					case 1:{
						std::cout << "Введите новое значение:" << '\n';
						char* newPerson = new char [20];
						std::cin >> newPerson;
						arr[i].setPerson(newPerson);
						delete[] newPerson;
						break;
					}
					case 2:{
						std::cout << "Введите новое значение:" << '\n';
						int newTime;
						std::cin >> newTime;
						arr[i].setTime(newTime);
						break;
					}
					case 3:{
						std::cout << "Введите новое значение:" << '\n';
						int newPrice;
						std::cin >> newPrice;
						arr[i].setPrice(newPrice);
						break;
					}
					case 4:{
						std::cout << "Введите новое значение:" << '\n';
						int newBaggage;
						std::cin >> newBaggage;
						arr[i].setBaggage(newBaggage);
						break;
					}
				}
			}
		}
	}
}
std::ostream &operator<<(std::ostream &out, const Ticket &ticket){
	out << ticket.Person << ' ' << ticket.Time << ' ' << ticket.Price << ' ' << ticket.Baggage << '\n';
	return out;
}
std::istream &operator>>(std::istream &in, Ticket &ticket){
	in >> ticket.Person >> ticket.Time >> ticket.Price >> ticket.Baggage;
	return in;
}
bool Ticket::operator==(const Ticket &ticket){
	if (strcmp(Person, ticket.Person) == 0){
		return true;
	}
	return false;
}
bool Ticket::operator<(const Ticket &ticket){
	if (strcmp(Person, ticket.Person) > 0){
		return true;
	}
	return false;
}
void Ticket::operator=(const Ticket &arr1){
	setPerson(arr1.Person);
	setTime(arr1.Time);
	setPrice(arr1.Price);
	setBaggage(arr1.Baggage);
}
Ticket::~Ticket(){
	total--;
	//std::cout << "Удаление ID" << id << std::endl;
	delete[] Person;
}

