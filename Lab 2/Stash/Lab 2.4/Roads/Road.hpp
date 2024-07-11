//
// Created by DJ Tape on 06.06.2024.
//

#ifndef LAB_2_4_ROAD_HPP
#define LAB_2_4_ROAD_HPP

#include <iostream>
#include <fstream>
#include <cstring>

class Ticket{
private:
	char* Person;
	int Time;
	int Price;
	int Baggage;
	static int total;
	int id;
public:
	friend std::ostream &operator<<(std::ostream &, const Ticket &);
	friend std::istream &operator>>(std::istream &, Ticket &);
	bool operator<(const Ticket &);
	bool operator==(const Ticket &);
	void operator=(const Ticket &);
	char* getPerson(){
		return Person;
	};
	int getTime(){
		return Time;
	};
	int getPrice(){
		return Price;
	};
	int getBaggage(){
		return Baggage;
	};
	void setPerson(const char* Person){
		delete[] this->Person;
		this->Person = new char[std::strlen(Person) + 1];
		strcpy(this->Person, Person);
	}
	void setTime(int Time){
		this->Time=Time;
	}
	void setPrice(int Price){
		this->Price=Price;
	}
	void setBaggage(int Baggage){
		this->Baggage=Baggage;
	}
	Ticket();
	Ticket(const char* Person, int Time, int Price, int Baggage);
	static int read_db(const char* FilenameFrom, Ticket* Arr, int &N);
	static int write_db(const char* FilenameTo, const Ticket* Arr, int N);
	static void sort_db(Ticket* Arr, int N);
	static void print_db(const Ticket* arr, int n);
	static Ticket* delete_word(Ticket* arr, int &n, int &N, bool IsInteractive);
	static void change_value(Ticket* arr, int n, bool IsInteractive);
	static Ticket* add_word(Ticket* arr, int &n, int &N, bool IsInteractive);
	Ticket(const Ticket& arr);
	~Ticket();
};



#endif //LAB_2_4_ROAD_HPP
