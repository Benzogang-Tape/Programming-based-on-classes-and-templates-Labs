#include <iostream>
#include "MyContainers/MySet.hpp"


int main() {
	setlocale(LC_ALL, "russian");
	MyVector<int> testVec;
	MySet<int> testSet;
	MySet<int> testSet1, testSet2;
	testSet1.addElement(1);
	testSet1.addElement(2);
	testSet1.addElement(3);
	testSet2.addElement(4);
	testSet2.addElement(5);
	testSet2.addElement(6);

	testSet = testSet1 + testSet2;
	std::cout << testSet << std::endl;

	testVec.addElement(54);
	testVec.addElement(54);
	testVec.deleteElement(14);
	testSet.addElement(54);
	testSet.addElement(54);
	testSet.delete_Element(54);
	std::cout << testVec << ' ' << testSet << std::endl;

	MySet<int> t1, t2, result;
	t1.addElement(12);
	t1.addElement(123);
	t1.addElement(23);
	t1.addElement(73);

	t2.addElement(12);
	t2.addElement(27);
	t2.addElement(1337);
	t2.addElement(73);

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
