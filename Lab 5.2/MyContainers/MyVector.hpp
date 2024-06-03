#ifndef LAB_5_2_MYVECTOR_HPP
#define LAB_5_2_MYVECTOR_HPP


#include <iostream>
#include <iomanip>
#include <cstring>

const int MAX_SIZE = 5;

template <class INF>

class MyVector
{
	typedef class MyVector<INF> Vector;
protected:
	INF *inf;
	int maxSize;
	int currentSize;
	void resize();
public:
	MyVector() : inf(nullptr), maxSize(MAX_SIZE), currentSize(0) {};
	MyVector(const MyVector&);
	~MyVector() { delete[] inf; }

	virtual void addElement(INF);
	void deleteElement(int);
	INF& operator [] (int);
	void sort();
	bool isElement(INF);
	int getSize() { return currentSize; }
	int getMaxSize() { return maxSize; }
	int find(INF);
	MyVector<INF>& operator = (const MyVector<INF>&);
	template<class U>
	friend std::ostream& operator <<(std::ostream&, const MyVector<U>&);
};

template<class INF>
inline void MyVector<INF>::resize() {
//	bool flag{};
	if (currentSize > maxSize) {
		maxSize *= 2;
//		flag = true;
	}
	else if (maxSize / 4 > currentSize) {
		maxSize /= 2;
//		flag = true;
	}
//	if (!flag) {
	auto temp = new INF[maxSize];
	for (int i{}; i < currentSize - 1; ++i)
		temp[i] = this->inf[i];
	delete[] inf;
	inf = temp;
//	}

}

template<class INF>
inline MyVector<INF>::MyVector(const MyVector& other) {
	maxSize = MAX_SIZE;
	currentSize = other.currentSize;
	inf = new INF[currentSize];
	for (int i{}; i < other.currentSize; ++i) {
		inf[i] = other.inf[i];
	}
}

template<class INF>
inline void MyVector<INF>::addElement(INF elem) {
	currentSize += 1;
	resize();
	inf[currentSize - 1] = elem;
}

template<class INF>
inline void MyVector<INF>::deleteElement(int idx) {
	if (idx < 0 or idx > currentSize)
		return;
	for (int i = idx; i < currentSize - 1; ++i)
		inf[i] = inf[i + 1];
	resize();
	currentSize--;
}

template<class INF>
inline INF& MyVector<INF>::operator[](int idx) {
	return *(inf + idx);
}

template<class INF>
inline void MyVector<INF>::sort() {
	for (int i{}; i < currentSize - 1; ++i) {
		for (int j = i + 1; j < currentSize; ++j) {
			if (inf[i] > inf[j]) {
				std::swap(inf[i], inf[j]);
			}
		}
	}
}

template<>
inline void MyVector<char *>::sort() {
	for (int i{}; i < currentSize -1; i++) {
		for (int j = i + 1; j < currentSize; ++j) {
			if (strcmp(inf[i], inf[j]) > 0) {
				std::swap(inf[i], inf[j]);
			}
		}
	}
}

template<class INF>
inline int MyVector<INF>::find(INF elem) {
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

template<class INF>
inline MyVector<INF>& MyVector<INF>::operator=(const MyVector<INF>& source) {
	if (this != &source) {
		this->currentSize = 0;
		delete[] inf;
		inf = new INF[currentSize];
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

template<class INF>
inline bool MyVector<INF>::isElement(INF elem) {
	if (this->find(elem) != -1)
		return true;
	return false;
}

#endif //LAB_5_2_MYVECTOR_HPP
