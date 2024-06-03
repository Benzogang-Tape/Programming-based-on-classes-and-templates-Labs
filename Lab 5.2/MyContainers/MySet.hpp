#ifndef LAB_5_2_MYSET_HPP
#define LAB_5_2_MYSET_HPP

#include "MyVector.hpp"

template <class Information>
class MySet: public MyVector<Information> {
public:
	explicit MySet(Information inf = NULL) : MyVector<Information>(){};
	bool operator == (MySet&);
	MySet& operator += (MySet&);
	MySet& operator -= (MySet&);
	MySet& operator *= (MySet&);

	void addElement(Information);
	void delete_Element(Information);

	template <class U>
	friend MySet<U> operator+(MySet<U>&, MySet<U>&);
	template <class U>
	friend MySet<U> operator-(MySet<U>&, const MySet<U>&);
	template <class U>
	friend MySet<U> operator*(MySet<U>&, MySet<U>&);
};

template<class Information>
inline bool MySet<Information>::operator==(MySet& other) {
	if (this->currentSize != other.currentSize) {
		return false;
	}
	for (int i{}; i < this->currentSize - 1; ++i) {
		if (this->find(other.inf[i]) == -1) {
			return false;
		}
	}
	return true;
}

template<class U>
inline MySet<U> operator+(MySet<U>& lhs, MySet<U>& rhs) {
	MySet<U> result;
	for (int i{}; i < lhs.currentSize; ++i) {
		result.addElement(lhs.inf[i]);
	}
	for (int j{}; j < rhs.currentSize; ++j) {
		if (result.find(rhs.inf[j]) == -1) {
			result.addElement(rhs.inf[j]);
		}
	}
	return result;
}

template<class Information>
inline MySet<Information>& MySet<Information>::operator+=(MySet<Information>& source) {
	*this = *this + source;
	return *this;
}

template<class U>
inline MySet<U> operator-(MySet<U>& lhs, const MySet<U>& rhs) {
	MySet<U> result = lhs;
	for (int i{}; i < rhs.currentSize; ++i) {
		if (result.isElement(rhs.inf[i])) {
			result.deleteElement(result.find(rhs.inf[i]) - 1);
		}
	}
	return result;
}

template<class Information>
inline MySet<Information>& MySet<Information>::operator-=(MySet<Information>& source) {
	*this = *this - source;
	return *this;
}

template<class U>
inline MySet<U> operator*(MySet<U>& lhs, MySet<U>& rhs) {
	MySet<U> result;
	for (int i{}; i < lhs.currentSize; ++i) {
		if (lhs.find(lhs.inf[i]) != -1 && rhs.find(lhs.inf[i]) != -1) {
			result.addElement(lhs.inf[i]);
		}
	}
	return result;
}

template<class Information>
inline MySet<Information>& MySet<Information>::operator*=(MySet<Information>& source) {
	*this = *this * source;
	return *this;
}

template<class Information>
inline void MySet<Information>::addElement(Information elem) {
	if (!this->isElement(elem)) {
		MyVector<Information>::addElement(elem);
	}
}

template<class Information>
inline void MySet<Information>::delete_Element(Information elem) {
	if (this->isElement(elem)) {
		MyVector<Information>::deleteElement(this->find(elem));
	}
}

#endif //LAB_5_2_MYSET_HPP
