#include "Product.hpp"

product::Product::Product()
{
	name = nullptr;
	cost = 0;
	shelfLife = 0;
	presense = false;
}

product::Product::Product(char* newName, double newCost, int newShelfLife, bool newPresence) : name(newName), cost(newCost), shelfLife(newShelfLife), presense(newPresence){}

product::Product::~Product()
{
	delete[] name;
}

char* product::Product::getName()
{
	return name;
}

double product::Product::getCost()
{
	return cost;
}

int product::Product::getShelfLife()
{
	return shelfLife;
}

bool product::Product::getPresense()
{
	return presense;
}

void product::Product::setName(char* newName)
{
	delete[] this->name;
	const size_t bufSz = strlen(newName) + 1;
	this->name = new char[bufSz];
	strncpy(this->name, newName, bufSz);
}

void product::Product::setCost(double newCost)
{
	this->cost = newCost;
}

void product::Product::setSheflLife(int newShelfLife)
{
	this->shelfLife = newShelfLife;
}

void product::Product::setPresence(bool newPresense)
{
	this->presense = newPresense;
}

void product::Product::editProduct()
{
	int userInput;
	while (true) {
		std::cout << "1. Čçěĺíčňü íŕçâŕíčĺ ňîâŕđŕ \t 4. Čçěĺíčňü íŕëč÷čĺ ňîâŕđŕ" << std::endl;
		std::cout << "2. Čçěĺíčňü ńňîčěîńňü ňîâŕđŕ \t 5. Âűőîä" << std::endl;
		std::cout << "3. Čçěĺíčňü ńđîę ăîäíîńňč ňîâŕđŕ" << std::endl;
		std::cin >> userInput;
		switch (userInput) {
			case 1:
			{
				char* newName = new char[64];
				std::cin >> newName;
				this->setName(newName);
				break;
			}
			case 2: {
				double newCost;
				std::cin >> newCost;
				this->setCost(newCost);
				break;
			}
			case 3:
				int newShelfLife;
				std::cin >> newShelfLife;
				this->setSheflLife(newShelfLife);
				break;
			case 4:
				bool newPresense;
				std::cin >> newPresense;
				this->setPresence(newPresense);
				break;
			case 5:
				return;
			default:
				std::cout << "Íĺäîďóńňčěűé ââîä" << std::endl << "Ďîďđîáóéňĺ ĺůĺ đŕç:" << std::endl;
		}
	}
}

std::istream& product::operator >> (std::istream& in, Product& product)
{
	char* newName = new char[64];
	std::cout << "Ââĺäčňĺ íŕçâŕíčĺ ňîâŕđŕ:" << std::endl;
	in >> newName;
	product.name = newName;
	std::cout << "Ââĺäčňĺ ńňîčěîńňü ňîâŕđŕ:" << std::endl;
	in >> product.cost;
	std::cout << "Ââĺäčňĺ ńđîę ăîäíîńňč ňîâŕđŕ:" << std::endl;
	in >> product.shelfLife;
	std::cout << "Ĺńňü ëč ňîâŕđ â íŕëč÷čč:" << std::endl;
	in >> product.presense;
	return in;
}

std::ifstream& product::operator >> (std::ifstream& in, Product& product)
{
	char* newName = new char[64];
	in >> newName;
	product.name = newName;
	in >> product.cost;
	in >> product.shelfLife;
	in >> product.presense;
	return in;
}

std::ostream& product::operator << (std::ostream& out, Product& product)
{
	out << product.name << std::setw(10);
	out << product.cost << ' ';
	out << product.shelfLife << ' ';
	out << product.presense << std::endl;
	return out;
}

std::ofstream& product::operator << (std::ofstream& out, Product& product)
{
	out << product.name << ' ' << product.cost << ' ' << product.shelfLife << ' ' << product.presense << std::endl;
	return out;
}


int product::productMenu()
{
	std::cout << " ============== ĂËŔÂÍÎĹ ĚĹÍŢ ========================\n";
	std::cout << "1 - ń÷čňŕňü áŕçó äŕííűő\t\t\t 5 - óäŕëčňü ďđîäóęň" << std::endl;
	std::cout << "2 - ńîőđŕíčňü áŕçó äŕííűő \t\t 6 - čçěĺíčňü ďđîäóęň" << std::endl;
	std::cout << "3 - ńîđňčđîâŕňü áŕçó äŕííűő \t\t 7 - âűâîä áŕçű íŕ ýęđŕí" << std::endl;
	std::cout << "4 - äîáŕâčňü ďđîäóęň \t\t\t 8 - âűőîä" << std::endl;
	std::cout << "Äë˙ âűáîđŕ îďĺđŕöčč ââĺäčňĺ öčôđó îň 1 äî 8" << std::endl;
	int userInput;
	std::cin >> userInput;
	std::cin.clear();
	std::cin.ignore(10, '\n');
	system("cls");
	return userInput;
}

int product::chooseProduct(Product* array, int n)
{
	int userInput = 0;
	std::cout << "Âűáĺđčňĺ ďđîäóęň:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << i + 1 << ". " << array[i].getName() << std::endl;
	std::cin >> userInput;
	return userInput - 1;
}

product::Product* product::readDataBase(const char* fileName, int& n)
{
	std::ifstream fin(fileName, std::ios::in);
	fin >> n;
	Product* newArray = new Product[n];
	for (int i = 0; i < n; i++)
		fin >> newArray[i];
	fin.close();
	return newArray;
}

void product::writeDataBase(const char* fileName, Product* array, int n)
{
	std::ofstream fout(fileName, std::ios::out);
	fout << n << std::endl;
	for (int i = 0; i < n; ++i)
		fout << array[i];
	fout.close();
}

void product::printDataBase(Product* array, int n)
{
	std::cout << n << " ďđîäóęňîâ: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << i + 1 << ". ";
		std::cout << array[i];
	}
	clearScreen();
}

bool product::operator>(product::Product& product1, product::Product& product2)
{
	if (product1.getCost() > product2.getCost())
		return true;
	else
		return false;
}

product::Product* product::addProduct(Product* oldArray, int& n)
{
	n += 1;
	Product* newArray = new Product[n];
	for (int i = 0; i < n - 1; i++)
		copyProduct(newArray[i], oldArray[i]);
	std::cin >> newArray[n - 1];
	std::cout << newArray[n - 1];
	clearScreen();
	return newArray;
}

product::Product* product::deleteProduct(Product* oldArray, int& n)
{
	int userInput, j = 0;
	Product* newArray = new Product[n - 1];
	userInput = chooseProduct(oldArray, n);
	for (int i = 0; i < n; i++) {
		if (n < userInput)
			copyProduct(newArray[i], oldArray[i]);
		else if (i > userInput)
			copyProduct(newArray[i - 1], oldArray[i]);
	}
	n -= 1;
	clearScreen();
	return newArray;
}

product::Product* product::sortProducts(Product* array, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (array[i] > array[j])
				exchangeProducts(array[j], array[i]);
	return array;
}

void product::copyProduct(Product& inputProduct, Product& outputProduct)
{
	inputProduct.setName(outputProduct.getName());
	inputProduct.setCost(outputProduct.getCost());
	inputProduct.setSheflLife(outputProduct.getShelfLife());
	inputProduct.setPresence(outputProduct.getPresense());
}

void product::exchangeProducts(Product& product1, Product& product2)
{
	char* tempName = new char[64];
	strncpy(tempName, product1.getName(), 64);
	double tempCost = product1.getCost();
	int tempShelfLife = product1.getShelfLife();
	bool tempPresense = product1.getPresense();
	product::copyProduct(product1, product2);

	product2.setName(tempName);
	product2.setCost(tempCost);
	product2.setPresence(tempPresense);
	product2.setSheflLife(tempShelfLife);
}

void product::clearScreen()
{
	std::cout << "Ââĺäčňĺ ëţáîé ńčěâîë, ÷ňîáű ďđîäîëćčňü:";
	std::getchar();
	system("cls");
}