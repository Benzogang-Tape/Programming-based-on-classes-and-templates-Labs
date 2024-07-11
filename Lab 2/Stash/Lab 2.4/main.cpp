#include "funcs.hpp"
#include "Roads/Road.hpp"
int Ticket::total = 0;
bool IsInteractive = 0;
int main(int argc, char* argv[]){
	if ((argc == 2) && (strcmp(argv[1], "i") == 0)){
		IsInteractive = true;
	}
	if (IsInteractive){
		return interactive();
	}
	else{
		return demo();
	}
}
int demo(){
	return 0;
}
int menu(){
	int command;
	std::cout << "Список команд:" << '\n';
	std::cout << "1. Прочитать файл" << '\n';
	std::cout << "2. Записать в файл" << '\n';
	std::cout << "3. Отсортировать базу данных" << '\n';
	std::cout << "4. Добавить новый объект" << '\n';
	std::cout << "5. Удалить объект" << '\n';
	std::cout << "6. Изменить значение в элементе" << '\n';
	std::cout << "7. Вывести базу данных" << '\n';
	std::cout << "8. Закончить работу" << '\n';
	std::cout << "Введите команду:" << '\n';
	std::cin >> command;
	return command;
}

int interactive(){
	const char* filename1 = "../../Planets.txt";
	const char* filename2 = "../../dbase2result.txt";
	int n = 0, N;
	std::ifstream fin(filename1, std::ios::in | std::ios::binary);
	fin >> N;
	fin.close();
	Ticket* array = new Ticket[N];
	while(true){
		switch(menu()){
			case 1:
				Ticket::read_db(filename1, array, n);
				break;
			case 2:
				Ticket::write_db(filename2, array, n);
				break;
			case 3:
				Ticket::sort_db(array, n);
				break;
			case 4:
				array = Ticket::add_word(array, n, N, IsInteractive);
				break;
			case 5:
				array = Ticket::delete_word(array, n, N, IsInteractive);
				break;
			case 6:
				Ticket::change_value(array, n, IsInteractive);
				break;
			case 7:
				Ticket::print_db(array, n);
				break;
			case 8:
				delete[] array;
				return 0;
		}
	}
	return 0;
}
