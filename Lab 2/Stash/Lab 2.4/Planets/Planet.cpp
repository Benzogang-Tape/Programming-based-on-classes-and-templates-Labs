////
//// Created by DJ Tape on 06.06.2024.
////
//
//#include "Planet.hpp"
//
//
//Planet::Planet() {
//	total++;
//	id = total;
//	//std::cout << "Создание ID " << id << std::endl;
//	Name = new char[1];
//	Name[0] = '\0';
//	Diameter = 0;
//	Life = 0;
//	Satellite = 0;
//}
//Planet::Planet(const Planet& arr){
//	Name = new char [std::strlen(arr.Name) + 1];
//	strncpy(Name, arr.Name, strlen(arr.Name) + 1);
//	Diameter = arr.Diameter;
//	Life = arr.Life;
//	Satellite = arr.Satellite;
//}
//Planet::Planet(const char* Name, int Diameter, int Life, int Satellite){
//	this->Name = new char [std::strlen(Name)+1];
//	std::strcpy(this->Name, Name);
//	this->Diameter=Diameter;
//	this->Life=Life;
//	this->Satellite=Satellite;
//}
//int Planet::read_db(const char* filename, Planet* arr, int &n) {
//	std::ifstream fin(filename, std::ios::in | std::ios::binary);
//	if (!fin){
//		std::cout<<"Файла " << filename << " нет!" << std::endl;
//		return 1;
//	}
//	fin >> n;
//	for (int i = 0; i < n; i++){
//		fin >> arr[i];
//	}
//	fin.close();
//	return 0;
//}
//int Planet::write_db(const char* filename, const Planet* arr, int n){
//	std::ofstream fin(filename, std::ios::out);
//	if (!fin){
//		std::cout<<"Файла " << filename << " нет!" << std::endl;
//		return 1;
//	}
//	fin << n << std::endl;
//	for (int i = 0; i < n; i++){
//		fin << arr[i];
//	}
//	fin.close();
//	return 0;
//}
//void Planet::sort_db(Planet* arr, int n){
//	for (int i = 0; i < n - 1; i++){
//		for (int j = 0; j < n - i - 1; j++){
//			if(arr[j] < arr[j + 1]){
//				Planet temp{arr[j]};
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//Planet* Planet::delete_word(Planet* arr, int &n, int&N, bool IsInteractive){
//	int count = 0, n1 = n;
//	if (n - 1 < int(N/4)){
//		N = N/2;
//		std::cout << "Размер массива избыточен, поэтому уменьшен вдвое" << '\n';
//	}
//	Planet* newArr = new Planet[N];
//	for(int i = 0; i < n; i++){
//		newArr[i] = arr[i];
//	}
//	char* word = new char [20];
//	if (IsInteractive){
//		std::cout << "Введите слово для удаления:" << '\n';
//		std::cin >> word;
//	}
//	else{
//		std::cout << "Удалим слово Neptune" << '\n';
//		strcpy(word, "Neptune");
//	}
//	for (int i = 0; i < n; i++){
//		if(!strcmp(word, newArr[i].Name)){
//			if (i != n - 1){
//				for (int j = i; j < n - 1; j++){
//					newArr[j] = newArr[j + 1];
//				}
//			}
//			else{
//				count--;
//			}
//			n--;
//		}
//		count++;
//	}
//	delete[] word;
//	if (count == n1){
//		std::cout << "Такого слова в словаре нет!" << std::endl;
//	}
//	delete[] arr;
//	return newArr;
//}
//void Planet::print_db(const Planet* arr, int n){
//	for (int i = 0; i < n; i++){
//		std::cout << arr[i];
//	}
//	std::cout << std::endl;
//}
//Planet* Planet::add_word(Planet* arr, int &n, int &N, bool IsInteractive){
//	if (n + 1 > N){
//		N = N * 2;
//		std::cout << "Достигнут предел базы данных! Размер увеличен вдвое!" << '\n';
//	}
//	Planet* newArr = new Planet[N];
//	for(int i = 0; i < n; i++){
//		newArr[i] = arr[i];
//	}
//	n++;
//	Planet newStruct;
//	if (IsInteractive){
//		std::cout << "Введите данные о планете:" << '\n';
//		std::cin >> newStruct;
//		std::cout << std::endl;
//	}
//	else{
//		std::cout << "Добавим следующие данные: Nibiru 12345 1 0" << '\n';
//		char* name = new char[10];
//		strcpy(name, "Nibiru");
//		newStruct.setName(name);
//		newStruct.setDiameter(12345);
//		newStruct.setLife(1);
//		newStruct.setSatellite(0);
//		delete[] name;
//	}
//	newArr[n - 1] = newStruct;
//	delete[] arr;
//	return newArr;
//}
//void Planet::change_value(Planet* arr, int n, bool IsInteractive){
//	Planet planet;
//	if (IsInteractive){
//		std::cout << "Выберите планету для редактирования:" << '\n';
//		std::cin >> planet;
//		for(int i = 0; i < n; i++){
//			if(planet == arr[i]){
//				int num;
//				std::cout << "Выберите параметр редактирования:" << '\n';
//				std::cout << "1. Изменить название планеты" << '\n';
//				std::cout << "2. Изменить длину диаметра планеты" << '\n';
//				std::cout << "3. Изменить наличие жизни на планете" << '\n';
//				std::cout << "4. Изменить кол-во спутников планеты" << '\n';
//				std::cin >> num;
//				switch (num){
//					case 1:{
//						std::cout << "Введите новое значение:" << '\n';
//						char* newName = new char [20];
//						std::cin >> newName;
//						arr[i].setName(newName);
//						delete[] newName;
//						break;
//					}
//					case 2:{
//						std::cout << "Введите новое значение:" << '\n';
//						int newDiameter;
//						std::cin >> newDiameter;
//						arr[i].setDiameter(newDiameter);
//						break;
//					}
//					case 3:{
//						std::cout << "Введите новое значение:" << '\n';
//						int newLife;
//						std::cin >> newLife;
//						arr[i].setLife(newLife);
//						break;
//					}
//					case 4:{
//						std::cout << "Введите новое значение:" << '\n';
//						int newSatellite;
//						std::cin >> newSatellite;
//						arr[i].setSatellite(newSatellite);
//						break;
//					}
//				}
//			}
//		}
//	}
//	else{
//		std::cout << "Изменим параметр наличия жизни на Марсе на 0: " << '\n';
//		char* name = new char[10];
//		strcpy(name, "Mars");
//		planet.setName(name);
//		for(int i = 0; i < n; i++){
//			if(planet == arr[i]){
//				arr[i].setLife(0);
//			}
//		}
//		delete[] name;
//	}
//}
//std::ostream &operator<<(std::ostream &out, const Planet &planet){
//	out << planet.Name << ' ' << planet.Diameter << ' ' << planet.Life << ' ' << planet.Satellite << '\n';
//	return out;
//}
//std::istream &operator>>(std::istream &in, Planet &planet){
//	in >> planet.Name >> planet.Diameter >> planet.Life >> planet.Satellite;
//	return in;
//}
//bool Planet::operator==(const Planet &planet){
//	if (strcmp(Name, planet.Name) == 0){
//		return true;
//	}
//	return false;
//}
//bool Planet::operator<(const Planet &planet){
//	if (strcmp(Name, planet.Name) > 0){
//		return true;
//	}
//	return false;
//}
//void Planet::operator=(const Planet &arr1){
//	setName(arr1.Name);
//	setDiameter(arr1.Diameter);
//	setLife(arr1.Life);
//	setSatellite(arr1.Satellite);
//}
//Planet::~Planet(){
//	total--;
//	//std::cout << "Удаление ID " << id << std::endl;
//	delete[] Name;
//}
