#include <iostream>
#include "MyContainers/MySet.hpp"


int main() {
	setlocale(LC_ALL, "russian");
	MyVector<int> testVec;
	MySet<int> testSet;
	testVec.addElement(2);
	testVec.addElement(2);
	testVec.deleteElement(10);
	testSet.addElement(2);
	testSet.addElement(2);
	testSet.delete_Element(2);
	std::cout << testVec << ' ' << testSet << std::endl;

	MySet<int> t1, t2, result;
	t1.addElement(7);
	t1.addElement(123);
	t1.addElement(23);
	t1.addElement(73);

	t2.addElement(7);
	t2.addElement(27);
	t2.addElement(2545);
	t2.addElement(73);
	//std::cout << "array 1:" << t1 << ", array 2:" << t2 << std::endl << std::endl;
	//std::cout << t1 << " + " << t2 << " => " << t1 + t2 << std::endl;
	//std::cout << t1 << " - " << t2 << " => " << t1 - t2 << std::endl;
	//std::cout << t2 << " - " << t1 << " => " << t2 - t1 << std::endl;
	//std::cout << t1 << " * " << t2 << " => " << t1 * t2 << std::endl;
	//std::cout << t1 << " == " << t2 << " => ";
	bool a = (t1 == t2);
	//std::cout << a;

	MyVector<char*> v;
	v.addElement(const_cast<char *>("Привет!"));
	v.addElement(const_cast<char *>("Привет!"));
	v.addElement(const_cast<char *>("Привет!"));
	v.addElement(const_cast<char *>("Привет!"));
	v.addElement(const_cast<char *>("Привет!"));
	std::cout << "Вектор v: " << v << std::endl;
	v.addElement(const_cast<char *>("Привет!"));
	v.addElement(const_cast<char *>("Привет!"));
	v.addElement(const_cast<char *>("Привет!"));
	std::cout << "Вектор v: " << v << std::endl;
	MyVector<char*> v1 = v;
	std::cout << "Вектор v1: " << v1 << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v1.deleteElement(0);
	std::cout << "Вектор v1: " << v1 << std::endl;
	MySet <char*> s, s1, s2;
	s.addElement(const_cast<char *>("Привет!"));
	s.addElement(const_cast<char *>("No"));
	char* str = const_cast<char *>("Hello!");
	s.addElement(str);
	std::cout << "Множество s: " << s << std::endl;
	s1.addElement(const_cast<char *>("Cat"));
	s1.addElement(const_cast<char *>("No"));
	s1.addElement(const_cast<char *>("Привет!"));
	std::cout << "Множество s1: " << s1 << std::endl;
	s2 = s1 - s;
	std::cout << "Множество s2=s1-s: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	s2 = s - s1;
	std::cout << "Множество s2=s-s1: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	s2 = s1 + s;
	std::cout << "Множество s2=s1+s: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	s2 = s1 * s;
	std::cout << "Множество s2=s1*s: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	MySet<char*> s3 = s2;
	std::cout << "Множество s3=s2: " << s3 << std::endl;
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
	return 0;
}
