#include <iostream>
#include "MyContainers/MySet.hpp"

int main() {
	std::cout << "Hello, World!" << std::endl;
	system("chcp 1251>nul");

	//---------------------VECTOR (CHAR *)------------------
	MyVector<char *> v;
	v.add_element(const_cast<char *>("Hello!"));
	v.add_element(const_cast<char *>("Привет!"));
	v.add_element(const_cast<char *>("Привет!"));
	v.add_element(const_cast<char *>("Привет!"));
	v.add_element(const_cast<char *>("Привет!"));
	v.add_element(const_cast<char *>("Привет!"));
	std::cout << "Вектор v: \n"
			  << v << std::endl;
	v.add_element(const_cast<char *>("Привет!"));
	v.add_element(const_cast<char *>("Привет!"));
	v.add_element(const_cast<char *>("Привет!"));
	std::cout << "Вектор v: \n"
			  << v << std::endl;
	MyVector<char *> v1 = v;
	std::cout << "Вектор v1: \n"
			  << v1 << std::endl;
	int size = v1.Size();
	for (int i = 0; i < size; i++)
		v1.delete_element(1);
	std::cout << "Вектор v1: \n"
			  << v1 << std::endl;

	// ---------------------VECTOR (INT)------------------
	MyVector<int> v_2;
	v_2.add_element(1);
	v_2.add_element(1);
	v_2.add_element(2);
	v_2.add_element(1);
	v_2.add_element(1);
	std::cout << "Вектор v_2: \n"
			  << v_2 << std::endl;
	v_2.add_element(1);
	v_2.add_element(1);
	v_2.add_element(1);
	std::cout << "Вектор v_2: \n"
			  << v_2 << std::endl;
	MyVector<int> v1_2 = v_2;
	std::cout << "Вектор v1_2: \n"
			  << v1_2 << std::endl;
	v1_2.sort();
	std::cout << "Вектор сортированный v1_2: \n"
			  << v1_2 << std::endl;
	int size_2 = v1_2.Size();
	for (int i = 0; i < size_2; i++)
		v1_2.delete_element(1);
	std::cout << "Вектор v1_2: \n" // тут мини баг
			  << v1_2 << std::endl;

//     // //---------------------SET (CHAR*)------------------------

	MySet<char *> s(), s1(), s2();
	s.add_element(const_cast<char *>("Yes"));
	s.add_element(const_cast<char *>("phrase"));
	s.add_element(const_cast<char *>("No"));
	char *str =const_cast<char *>("Hello!");
	s.add_element(str);
	std::cout << "Множество s: \n" << s << std::endl;
	s1.add_element(const_cast<char *>("Cat"));
	s1.add_element(const_cast<char *>("No"));
	s1.add_element(const_cast<char *>("phrase"));
	std::cout << "Множество s1: \n" << s1 << std::endl;
	s2 = (s1 - s);
	std::cout << "Множество s2=s1-s:\n " << s2 << std::endl;
	std::cout << "Множество s1: \n" << s1 << std::endl;
	std::cout << "Множество s:\n " << s << std::endl;
	s2 = s - s1;
	std::cout << "Множество s2=s-s1:\n " << s2 << std::endl;
	std::cout << "Множество s1:\n " << s1 << std::endl;
	std::cout << "Множество s:\n " << s << std::endl;
	s2 = s1 + s;
	std::cout << "Множество s2=s1+s:\n " << s2 << std::endl;
	std::cout << "Множество s1:\n " << s1 << std::endl;
	std::cout << "Множество s:\n " << s << std::endl;
	s2 = s1 * s;
	std::cout << "Множество s2=s1*s:\n " << s2 << std::endl;
	std::cout << "Множество s1:\n " << s1 << std::endl;
	std::cout << "Множество s:\n " << s << std::endl;
	MySet<char *> s3 = s2;
	std::cout << "Множество s3=s2:\n " << s3 << std::endl;
	if (s3 == s2)
		std::cout << "Множество s3=s2\n";
	else
		std::cout << "Множество s3!=s2\n";
	if (s3 == s1)
		std::cout << "Множество s3=s1\n";
	else
		std::cout << "Множество s3!=s1\n";
	if (s1 == s3)
		std::cout << "Множество s1=s3\n";
	else
		std::cout << "Множество s1!=s3\n";

//---------------------SET (INT)------------------------

	MySet<int> s_2(), s1_2(), s2_2();
	s_2.add_element(2);
	s_2.add_element(3);
	int str_2 = 4;
	s_2.add_element(str_2);
	std::cout << "Множество s_2: \n" << s_2 << std::endl;
	s1_2.add_element(3);
	s1_2.add_element(4);
	s1_2.add_element(5);
	std::cout << "Множество s1_2: \n" << s1_2 << std::endl;
	s2_2 = (s1_2 - s_2);
	std::cout << "Множество s2_2=s1_2-s_2:\n " << s2_2 << std::endl;
	std::cout << "Множество s1_2: \n" << s1_2 << std::endl;
	std::cout << "Множество s_2:\n " << s_2 << std::endl;
	s2_2 = s_2 - s1_2;
	std::cout << "Множество s2_2=s_2-s1_2:\n " << s2_2 << std::endl;
	std::cout << "Множество s1_2:\n " << s1_2 << std::endl;
	std::cout << "Множество s_2:\n " << s_2 << std::endl;
	s2_2 = s1_2 + s_2;
	std::cout << "Множество s2_2=s1_2+s_2:\n " << s2_2 << std::endl;
	std::cout << "Множество s1_2:\n " << s1_2 << std::endl;
	std::cout << "Множество s_2:\n " << s_2 << std::endl;
	s2_2 = s1_2 * s_2;
	std::cout << "Множество s2_2=s1_2*s_2:\n " << s2_2 << std::endl;
	std::cout << "Множество s1_2:\n " << s1_2 << std::endl;
	std::cout << "Множество s_2:\n " << s_2 << std::endl;
	MySet<int> s3_2 = s2_2;
	std::cout << "Множество s3_2=s2_2:\n " << s3_2 << std::endl;
	if (s3_2 == s2_2)
		std::cout << "Множество s3_2=s2_2\n";
	else
		std::cout << "Множество s3_2!=s2_2\n";
	if (s3_2 == s1_2)
		std::cout << "Множество s3_2=s1_2\n";
	else
		std::cout << "Множество s3_2!=s1_2\n";
	if (s1_2 == s3_2)
		std::cout << "Множество s1_2=s3_2\n";
	else
		std::cout << "Множество s1_2!=s3_2\n";
	return 0;
}
