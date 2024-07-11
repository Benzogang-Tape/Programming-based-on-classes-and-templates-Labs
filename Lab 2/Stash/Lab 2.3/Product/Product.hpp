//
// Created by DJ Tape on 04.06.2024.
//

#ifndef LAB_2_3_PRODUCT_HPP
#define LAB_2_3_PRODUCT_HPP


#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale>
#include <cstring>

namespace product
{
	class Product {
	private:
		char* name;
		double cost;
		int shelfLife;
		bool presense;
	public:
		Product();
		Product(char*, double, int, bool);
		~Product();

		char* getName();
		double getCost();
		int getShelfLife();
		bool getPresense();

		void setName(char*);
		void setCost(double);
		void setSheflLife(int);
		void setPresence(bool);

		void editProduct();

		friend std::istream& operator >> (std::istream&, Product&);
		friend std::ifstream& operator >> (std::ifstream&, Product&);
		friend std::ostream& operator << (std::ostream&, Product&);
		friend std::ofstream& operator << (std::ofstream&, Product&);
	};

	int productMenu();
	int chooseProduct(Product*, int);
	Product* readDataBase(const char*, int&);
	void writeDataBase(const char*, Product*, int);
	void printDataBase(Product*, int);
	void copyProduct(Product&, Product&);
	void exchangeProducts(Product&, Product&);
	void clearScreen();

	bool operator > (product::Product&, product::Product&);

	Product* addProduct(Product*, int&);
	Product* deleteProduct(Product*, int&);
	Product* sortProducts(Product*, int);
}

#endif //LAB_2_3_PRODUCT_HPP
