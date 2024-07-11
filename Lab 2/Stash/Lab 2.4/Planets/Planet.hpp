////
//// Created by DJ Tape on 06.06.2024.
////
//
//#ifndef LAB_2_4_PLANET_HPP
//#define LAB_2_4_PLANET_HPP
//
//
//#include <iostream>
//#include <fstream>
//#include <cstring>
//
//class Planet{
//private:
//	char* Name;
//	int Diameter;
//	int Life;
//	int Satellite;
//	static int total;
//	int id;
//public:
//	friend std::ostream& operator<<(std::ostream &, const Planet &);
//	friend std::istream &operator>>(std::istream &, Planet &);
//	bool operator<(const Planet &);
//	bool operator==(const Planet &);
//	void operator=(const Planet &);
//	char* getName(){
//		return Name;
//	};
//	int getDiameter(){
//		return Diameter;
//	};
//	int getLife(){
//		return Life;
//	};
//	int getSatellite(){
//		return Satellite;
//	};
//	void setName(const char* Name){
//		delete[] this->Name;
//		this->Name = new char[std::strlen(Name) + 1];
//		strcpy(this->Name, Name);
//	}
//	void setDiameter(int Diameter){
//		this->Diameter=Diameter;
//	}
//	void setLife(int Life){
//		this->Life=Life;
//	}
//	void setSatellite(int Satellite){
//		this->Satellite=Satellite;
//	}
//	Planet();
//	Planet (const char* Name, int Diameter, int Life, int Satellite);
//	static int read_db(const char* FilenameFrom, Planet* Arr, int &N);
//	static int write_db(const char* FilenameTo, const Planet* Arr, int N);
//	static void sort_db(Planet* Arr, int N);
//	static void print_db(const Planet* arr, int n);
//	static Planet* delete_word(Planet* arr, int &n, int&N, bool IsInteractive);
//	static void change_value(Planet* arr, int n, bool IsInteractive);
//	static Planet* add_word(Planet* arr, int &n, int &N, bool IsInteractive);
//	Planet (const Planet& arr);
//	~Planet();
//};
//
//
//#endif //LAB_2_4_PLANET_HPP
