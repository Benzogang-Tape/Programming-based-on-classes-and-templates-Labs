#ifndef LAB_2_2_PLANET_HPP
#define LAB_2_2_PLANET_HPP


#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <algorithm>

class Planet
{
private:
	char *_name;
	size_t diameter;
	bool hasLife;
	size_t satelliteCount;

public:
	const char *getName();
	size_t getDiametr();
	bool getAlive();
	size_t getSatelites();

	void setName(char *name);
	void setDiametr(size_t diametr);
	void setAlive(bool alive);
	void setSatelites(size_t satel);
	void setPlanet(char *name, size_t diametr, bool alive, size_t satel);

	void operator=(const Planet &planet);

	bool operator==(Planet &planet);
	bool operator>(Planet &planet); // sorted by diametr
	bool operator<(Planet &planet); // sorted by diametr

	Planet(int len = Planet::NAME_LEN); // NOLINT
	Planet(const Planet &tmp);          // NOLINT
	Planet(char *naming, size_t diam, bool aliving, size_t satel, int len = 40);
	~Planet();

	static int edit(Planet *planets, int n_planet, int line, char *name, int diam, bool alive, int satel);

	static int read_db(char *file_name, int &n_planet, int &mas_size_planet, Planet *planets);

	static int add_db(Planet* planets, int &n_planet, int& mas_size_planet, char *name, size_t diametr, bool alive, size_t satelites);

	static int delete_db(char *file_name, int line, int &n_planet, int &mas_size_planet);

	static void print_db(char *file_name, int n_planet);

	static int write_db(char *file_name, Planet *planets, int n_planet);

	static void getCountLines(char *file_name, int &n_planet);

	static int find(Planet *planets, int n_planet);

	static void showArray(Planet *mas, int n_planet);

	static void sort_by_diametr_db(Planet *planets, int n_planet);

	static void mySwap(Planet &lhs, Planet &rhs);

	static Planet *decrease_arr(Planet *a, int old_size);

	static void increase_arr(Planet *a, int& old_size);

	static const int SETW_SIZE = 12;

	static const int NAME_LEN = 40;

	// static inline unsigned n_planet{0}
};
// std::istream& operator>>(std::istream& in, Planet planet);
void slashEqual();
void slash();
std::ostream &operator<<(std::ostream &out, Planet &planet);
std::istream &operator>>(std::istream &in, Planet &planet);
int demo();

#endif //LAB_2_2_PLANET_HPP
