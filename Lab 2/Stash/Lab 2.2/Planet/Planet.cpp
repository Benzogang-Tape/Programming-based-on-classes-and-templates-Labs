#include "Planet.hpp"

void Planet::increase_arr(Planet *a, int &old_size)
{
	Planet *newArr = new Planet[old_size * 2];
	for (int i = 0; i < old_size * 2; i++)
	{

		if (i < old_size)
		{
			newArr[i] = a[i];
		}
		else
		{
			newArr[i] = Planet{};
		}
	}
	a = newArr;
	old_size *= 2; //
}

Planet *Planet::decrease_arr(Planet *a, int old_size)
{
	Planet *new_arr = new Planet[old_size / 2]{};
	for (int i = 0; i < old_size; ++i)
		new_arr[i] = a[i];
	delete[] a;
	return new_arr;
}

std::ostream &operator<<(std::ostream &out, Planet &planet)
{
	out << std::setw(Planet::SETW_SIZE) << std::left << planet.Planet::getName() << std::setw(Planet::SETW_SIZE) << planet.Planet::getDiametr() << std::setw(Planet::SETW_SIZE) << planet.Planet::getAlive() << planet.Planet::getSatelites();
	return out;
}

bool Planet::operator==(Planet &planet)
{
	if (strcmp(_name, planet._name) == 0 && diameter == planet.diameter && satelliteCount == planet.satelliteCount && hasLife == planet.hasLife)
		return true;
	return false;
}

bool Planet::operator>(Planet &planet)
{
	return (diameter > planet.diameter ? 1 : 0);
}
bool Planet::operator<(Planet &planet)
{
	return (diameter < planet.diameter ? 1 : 0);
}

void Planet::operator=(const Planet &planet)
{
	strcpy(_name, planet._name);
	diameter = planet.diameter;
	hasLife = planet.hasLife;
	satelliteCount = planet.satelliteCount;
}

void slashEqual()
{
	std::cout << "=======================================\n";
}

void slash()
{
	std::cout << "---------------------------------------\n";
}
void Planet::mySwap(Planet &lhs, Planet &rhs)
{
	Planet tmp;
	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
void Planet::sort_by_diametr_db(Planet *planets, int n_planet)
{
	bool exit = 1;
	for (int i = 0; i < n_planet; i++)
	{
		exit = 1;
		for (int j = 0; j < n_planet - 1; j++)
		{
			if (planets[j] > planets[j + 1])
			{
				Planet::mySwap(planets[j + 1], planets[j]);
				exit = 0;
			}
		}
		if (exit)
		{
			break;
		}
	}
}
std::istream &operator>>(std::istream &in, Planet &planet)
{
	char *name = new char[Planet::NAME_LEN];
	size_t diam, satel;
	bool alive;

	in >> name >> diam >> alive >> satel;
	planet.Planet::setName(name);
	planet.Planet::setDiametr(diam);
	planet.Planet::setAlive(alive);
	planet.Planet::setSatelites(satel);
	delete[] name;
	return in;
}

Planet::Planet(int len)
{
	// std::cout << "i created Planet" << std::endl;
	_name = new char[len];
	strcpy(_name, "defaultN");
	diameter = 0;
	hasLife = 0;
	satelliteCount = 0;
}

Planet::Planet(const Planet &tmp)
{
	_name = new char[strlen(tmp._name)];
	diameter = tmp.diameter;
	hasLife = tmp.hasLife;
	satelliteCount = tmp.satelliteCount;
	strcpy(_name, tmp._name);
}

Planet::Planet(char *naming, size_t diam, bool aliving, size_t satel, int len)
{
	// std::cout << "i created Planet by overloaded constructor" << std::endl;
	_name = new char[strlen(naming)];
	strcpy(_name, naming);
	diameter = diam;
	hasLife = aliving;
	satelliteCount = satel;
}

Planet::~Planet()
{
	// std::cout << "i annihilated Planet" << std::endl;
	delete[] _name;
}

void Planet::setName(char *name)
{
	strcpy(this->_name, name);
}
void Planet::setDiametr(size_t diametr)
{
	this->diameter = diametr;
}

void Planet::setAlive(bool alive)
{
	this->hasLife = alive;
}

void Planet::setSatelites(size_t satel)
{
	this->satelliteCount = satel;
}

void Planet::setPlanet(char *name, size_t diametr, bool alive, size_t satel)
{
	this->Planet::setName(name);
	this->Planet::setDiametr(diametr);
	this->Planet::setAlive(alive);
	this->Planet::setSatelites(satel);
}

size_t Planet::getDiametr()
{
	return this->diameter;
}

size_t Planet::getSatelites()
{
	return this->satelliteCount;
}

bool Planet::getAlive()
{
	return this->hasLife;
}

const char *Planet::getName()
{
	return this->_name;
}

int Planet::edit(Planet *planets, int n_planet, int line, char *name, int diam, bool alive, int satel)
{
	if (line > n_planet)
	{
		std::cout << "Такой строки нет в бд((\n";
		return -1;
	}
	planets[line - 1].Planet::setPlanet(name, diam, alive, satel);
	return 1;
}

int Planet::read_db(char *file_name, int &n_planet, int &mas_size_planet, Planet *planets)
{

	std::fstream source(file_name, std::ios::in);
	source.seekg(0, std::ios_base::beg);
	if (!source)
	{
		std::cout << "Ошибка откытия фалйа в read_db" << std::endl;
		return 1;
	}

	Planet::getCountLines(file_name, n_planet);
	if (n_planet > mas_size_planet)
	{
		Planet::increase_arr(planets, mas_size_planet);
	}

	size_t diam, satel;
	char *name = new char[Planet::NAME_LEN];
	bool alive;
	int i = 0;
	for (i; i < n_planet; i++)
	{
		source >> name >> diam >> alive >> satel;
		// std::cout << i << "|   i read\n";
		// std::cout << name << " " << diam << " " << alive << " " << satel << std::endl;
		planets[i].Planet::setPlanet(const_cast<char *>(name), diam, alive, satel);
		// std::cout << count << " " << name << std::endl;
	}

	source.close();
	delete[] name;
	return i;
}

void Planet::getCountLines(char *file_name, int &n_planet)
{
	std::ifstream source(file_name);
	source.seekg(0, std::ios::end);
	int end = source.tellg();
	source.seekg(0, std::ios::beg);
	if (end - source.tellg() == 0)
	{
		n_planet = 0;
	}
	else
	{
		n_planet = std::count(std::istreambuf_iterator<char>(source),
							  std::istreambuf_iterator<char>(), '\n') +
				   1;
	}
	source.close();
}

int Planet::write_db(char *file_name, Planet *planets, int n_planet)
{
	std::fstream source;
	source.open(file_name, std::ios::out);
	source.clear();
	source.seekg(0, std::ios_base::beg);
	if (!source)
	{
		std::cout << "не удалось открыть фалй в write_db" << std::endl;
		return -1;
	}
	for (int i = 0; i < n_planet; i++)
	{
		if (i)
		{
			source << std::endl;
		}
		source << planets[i];
	}
	source.close();
	return 0;
}

void Planet::print_db(char *file_name, int n_planet)
{
	std::fstream fout;
	fout.open(file_name, std::ios::in);
	if (!fout)
	{
		std::cout << "не удалось открыть фалй в print_db\n";
	}
	fout.seekg(0, std::ios_base::beg);
	int satel, diamt;
	bool alive;
	char *name = new char[Planet::NAME_LEN];
	for (int i = 0; i < n_planet; i++)
	{
		fout >> name >> diamt >> alive >> satel;
		std::cout << std::setw(Planet::SETW_SIZE) << std::left << name << std::setw(Planet::SETW_SIZE) << diamt << std::setw(Planet::SETW_SIZE) << alive << satel << std::endl;
	}

	delete[] name;
	fout.close();
}

int Planet::add_db(Planet *planets, int &n_planet, int &mas_size_planet, char *name, size_t diametr, bool alive, size_t satelites)
{

	if (n_planet + 1 > mas_size_planet)
	{
		std::cout << "Превышен размер массива\n";
		Planet::increase_arr(planets, mas_size_planet);
		// return -1;
	}
	planets[n_planet].setPlanet(name, diametr, alive, satelites);
	n_planet++;
	return 0;
}

int Planet::delete_db(char *file_name, int line, int &n_planet, int &mas_size_planet)
{
	Planet *tmp_planets = new Planet[n_planet];
	Planet::read_db(file_name, n_planet, mas_size_planet, tmp_planets);
	std::ofstream source;
	source.open(file_name, std::ios::trunc | std::ios::binary);

	if (!source)
	{
		std::cout << "не удалось открыть фалй в delete_db\n"
				  << std::endl;
		return -1;
	}
	bool wasAdded = 0;
	for (int i = 0; i < n_planet; i++)
	{
		if (i + 1 != line)
		{
			if (wasAdded)
			{
				source << std::endl;
			}
			wasAdded = 1;
			source << tmp_planets[i];
			source.flush();
		}
	}
	n_planet--;
	source.close();
	delete[] tmp_planets;
	return 0;
}

void Planet::showArray(Planet *mas, int n_planet)
{
	for (int i = 0; i < n_planet; i++)
	{
		std::cout << mas[i] << std::endl;
	}
}

int demo()
{

	char *source_file = const_cast<char *>("source_planet.txt");
	std::cout << "смотри что я умею!\n";
	int n_planet = 0, mas_size_planet = 0;
	Planet::getCountLines(source_file, n_planet);
	mas_size_planet = 50;
	Planet *planets = new Planet[mas_size_planet]{};
	Planet::read_db(source_file, n_planet, mas_size_planet, planets);
	slashEqual();
	std::cout << "            ВЫВОДИТЬ БД\n";
	Planet::print_db(source_file, n_planet);
	slashEqual();
	std::cout << "            ДОБАВЛЯТЬ ПЛАНЕТЫ\n";
	Planet::print_db(source_file, n_planet);
	slash();
	Planet::add_db(planets, n_planet, mas_size_planet, const_cast<char *>("iAdded"), 247, 1, 2462);
	Planet::write_db(source_file, planets, n_planet);
	Planet::print_db(source_file, n_planet);
	slashEqual();
	std::cout << "            СОРТИРОВАТЬ ПЛАНЕТЫ\n";
	Planet::print_db(source_file, n_planet);
	slash();
	Planet::getCountLines(source_file, n_planet);
	Planet::read_db(source_file, n_planet, mas_size_planet, planets);
	slash();
	Planet::sort_by_diametr_db(planets, n_planet);
	Planet::write_db(source_file, planets, n_planet);
	Planet::print_db(source_file, n_planet);
	slashEqual();
	std::cout << "            УДАЛЯТЬ ПЛАНЕТЫ\n";
	Planet::print_db(source_file, n_planet);
	slash();
	Planet::delete_db(source_file, 2, n_planet, mas_size_planet);
	Planet::read_db(source_file, n_planet, mas_size_planet, planets);
	Planet::print_db(source_file, n_planet);
	slashEqual();
	std::cout << "            РЕДАКТИРОВАТЬ ПЛАНЕТУ\n";
	Planet::print_db(source_file, n_planet);
	slash();
	Planet::edit(planets, n_planet, 5, const_cast<char *>("iWasEdited"), 134, 0, 131);
	Planet::write_db(source_file, planets, n_planet);
	Planet::print_db(source_file, n_planet);
	slashEqual();
	// char *source_file = const_cast<char *>("source_planet.txt");
	// std::cout << "смотри что я умею!\n";
	// int n_planet = 0, mas_size_planet = 0;
	// Planet::getCountLines(source_file, n_planet);
	// mas_size_planet = n_planet;
	// Planet *planets = new Planet[mas_size_planet]{};

	// Planet::read_db(source_file, n_planet, mas_size_planet, planets);
	// *planets = Planet::increase_arr(planets, mas_size_planet);
	// planets[2].setPlanet(const_cast<char *>("iAdded"), 247, 1, 2462);
	// planets[3].setPlanet(const_cast<char *>("iAdded"), 247, 1, 2462);
	// Planet::showArray(planets, 4);
	delete[] planets;
	return 0;
}
