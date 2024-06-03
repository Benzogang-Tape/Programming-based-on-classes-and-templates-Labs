#ifndef LAB_5_2_MYVECTOR_HPP
#define LAB_5_2_MYVECTOR_HPP


#include <iostream>
#include <iomanip>
#include <cstring>

const int MAX_SIZE = 5;

template <class Information>

class MyVector
{
	typedef class MyVector<Information> Vector;
protected:
	Information *inf;
	int maxSize;
	int currentSize;
	void resize();
public:
	MyVector() : inf(nullptr), maxSize(MAX_SIZE), currentSize(0) {};
	MyVector(const MyVector&);
	~MyVector() { delete[] inf; }

	virtual void addElement(Information);
	void deleteElement(int);
	Information& operator [] (int);
	void sort();
	bool isElement(Information);
	int getSize() { return currentSize; }
	int getMaxSize() { return maxSize; }
	int find(Information);
	MyVector<Information>& operator = (const MyVector<Information>&);
	template<class U>
	friend std::ostream& operator <<(std::ostream&, const MyVector<U>&);
};

template<class Information>
inline void MyVector<Information>::resize() {
	if (currentSize > maxSize)
		maxSize *= 2;
	else if (maxSize / 4 > currentSize)
		maxSize /= 2;
	auto temp = new Information[maxSize];
	for (int i{}; i < currentSize - 1; ++i)
		temp[i] = this->inf[i];
	delete[] inf;
	inf = temp;
}

template<class Information>
inline MyVector<Information>::MyVector(const MyVector& other) {
	maxSize = MAX_SIZE;
	currentSize = other.currentSize;
	inf = new Information[currentSize];
	for (int i{}; i < other.currentSize; ++i) {
		inf[i] = other.inf[i];
	}
}

template<class Information>
inline void MyVector<Information>::addElement(Information elem) {
	currentSize += 1;
	resize();
	inf[currentSize - 1] = elem;
}

template<class Information>
inline void MyVector<Information>::deleteElement(int idx) {
	if (idx < 0 or idx > currentSize)
		return;
	for (int i = idx; i < currentSize - 1; ++i)
		inf[i] = inf[i + 1];
	resize();
	currentSize--;
}

template<class Information>
inline Information& MyVector<Information>::operator[](int idx) {
	return *(inf + idx);
}

template<class Information>
inline void MyVector<Information>::sort() {
	for (int i{}; i < currentSize - 1; ++i) {
		for (int j = i + 1; j < currentSize; ++j) {
			if (inf[i] > inf[j]) {
				std::swap(inf[i], inf[j]);
			}
		}
	}
}

template<class Information>
inline int MyVector<Information>::find(Information elem) {
	for (int i{}; i < currentSize; ++i)
		if (inf[i] == elem)
			return i + 1;
	return -1;
}

template<>
inline int MyVector<char*>::find(char* elem) {
	for (int i{}; i < currentSize; ++i) {
		if (strncmp(inf[i], elem, sizeof(*elem)) == 0) {
			return i + 1;
		}
	}
	return -1;
}

template<class Information>
inline MyVector<Information>& MyVector<Information>::operator=(const MyVector<Information>& source) {
	if (this != &source) {
		this->currentSize = 0;
		delete[] inf;
		inf = new Information[currentSize];
		for (int i{}; i < source.currentSize; ++i) {
			this->addElement(source.inf[i]);
		}
	}
	return *this;
}

template<class U>
inline std::ostream& operator<<(std::ostream& out, const MyVector<U>& elem) {
	if (elem.currentSize == 0) {
		out << "[EMPTY]";
		return out;
	}
	out << '{';
	for (int i{}; i < elem.currentSize - 1; ++i) {
		out << elem.inf[i] << ", ";
	}
	out << elem.inf[elem.currentSize - 1];
	out << '}';
	return out;
}

template<class Information>
inline bool MyVector<Information>::isElement(Information elem) {
	if (this->find(elem) != -1)
		return true;
	return false;
}

#endif //LAB_5_2_MYVECTOR_HPP
