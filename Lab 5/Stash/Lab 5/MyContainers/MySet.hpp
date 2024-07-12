#ifndef LAB_5_MYSET_HPP
#define LAB_5_MYSET_HPP


#include <iostream>
#include "MyVector.hpp"


template <class TYPE>
class MySet : public MyVector<TYPE>
{
public:
	MySet<TYPE>() : MyVector<TYPE>(){};
	MySet(const MySet<TYPE> &el);

	template <class U>
	friend std::ostream &operator<<(std::ostream &out, MySet<U> &s);

	template <class U>
	friend MySet<U> operator+(MySet<U> &s1, MySet<U> &s2);

	MySet<TYPE> operator=(const MySet<TYPE> v);

	template <class U>
	friend MySet<U> operator-(MySet<U> &s1, MySet<U> &s2);

	template <class U>
	friend MySet<U> operator*(MySet<U> &s1, MySet<U> &s2);

	bool operator==(MySet<TYPE> &s);

	MySet<TYPE> &operator+=(MySet<TYPE> &s);

	MySet<TYPE> &operator-=(MySet<TYPE> &s);

	MySet<TYPE> &operator*=(MySet<TYPE> &s);

	void add_element(TYPE el);

	void delete_element(TYPE el);

	bool is_element(TYPE el);

private:
	int q_find(TYPE to_find);
};

/*template<class TYPE>
MySet<TYPE>::MySet() : MyVector<TYPE>() {

}*/

template <class TYPE>
MySet<TYPE>::MySet(const MySet<TYPE> &el)
{
	MySet<TYPE>::_maxsize = el._maxsize;
	MySet<TYPE>::_size = el._size;
	MySet<TYPE>::_pdata = new int[el._maxsize];
	for (int i = 0; i < MySet<TYPE>::_size; i++)
	{
		MySet<TYPE>::_pdata[i] = el._pdata[i];
	}
}
template <>
MySet<char *>::MySet(const MySet<char *> &el)
{
	_maxsize = el._maxsize;
	_size = el._size;
	_pdata = new char *[el._maxsize];
	int len_word;
	for (int i = 0; i < _maxsize; i++)
	{
		if (el._pdata[i] == NULL)
		{
			len_word = 5;
		}
		else
		{
			len_word = strlen(el._pdata[i]) + 1;
		}
		delete[] _pdata[i];
		_pdata[i] = new char[len_word];
		strcpy(_pdata[i], el._pdata[i]);
	}
}

template <class TYPE>
int MySet<TYPE>::q_find(TYPE to_find)
{
	int l = 0;                      // левая граница
	int r = MySet<TYPE>::_size - 1; // правая граница
	int mid;
	while ((l <= r))
	{
		mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
		if (MySet<TYPE>::_pdata[l] == to_find)
		{
			return l + 1; // проверяем ключ со серединным элементом
		}
		else if (MySet<TYPE>::_pdata[r] == to_find)
		{
			return r + 1; // проверяем ключ со серединным элементом
		}
		else if (MySet<TYPE>::_pdata[mid] == to_find)
		{
			return mid + 1; // проверяем ключ со серединным элементом
		}
		else if (MySet<TYPE>::_pdata[mid] > to_find)
			r = mid - 1; // проверяем, какую часть нужно отбросить
		else
			l = mid + 1;
	}
	return -1;
}

template <>
int MySet<char *>::q_find(char *to_find)
{
	int l = 0;         // левая граница
	int r = _size - 1; // правая граница
	int mid;
	while ((l <= r))
	{
		mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
		if (strcmp(_pdata[l], to_find) == 0)
		{
			return l + 1; // проверяем ключ со серединным элементом
		}
		else if (strcmp(_pdata[r], to_find) == 0)
		{
			return r + 1; // проверяем ключ со серединным элементом
		}
		else if (strcmp(_pdata[mid], to_find) == 0)
		{
			return mid + 1; // проверяем ключ со серединным элементом
		}
		else if (strcmp(_pdata[mid], to_find) > 0)
			r = mid - 1; // проверяем, какую часть нужно отбросить
		else
			l = mid + 1;
	}
	return -1;
}

template <class TYPE>
void MySet<TYPE>::add_element(TYPE el)
{
	if (!is_element(el))
	{
		MyVector<int>::add_element(el);
	}
	else
	{
		cout << "Такой элемент уже есть, брат\n";
	}
}

template <>
void MySet<char *>::add_element(char *el)
{
	if (!is_element(el))
	{
		MyVector<char *>::add_element(el);
	}
	else
	{
		cout << "Такой элемент уже есть, брат\n";
	}
}
template <class TYPE>
void MySet<TYPE>::delete_element(TYPE el)
{
	if (MySet<TYPE>::_size == 0)
	{
		cout << "а туть уже пусто...\n";
		return;
	}
	if (MySet<TYPE>::_size == 1)
	{
		MySet<TYPE>::_pdata[0] = -2;
		--MySet<TYPE>::_size;
		return;
	}
	else
	{
		int pos = q_find(el) - 1;
		if (pos == -2)
		{
			cout << "Бро.... элемента |" << el << "|туть нет....\n";
			return;
		}
		for (int i = pos; i < MySet<TYPE>::_size - 1; i++)
		{
			MySet<TYPE>::_pdata[i] = MySet<TYPE>::_pdata[i + 1];
		}
		TYPE *newArr = new TYPE[MySet<TYPE>::_size - 1];
		for (int i = 0; i < MySet<TYPE>::_size - 1; i++)
		{
			newArr[i] = MySet<TYPE>::_pdata[i];
		}
		MySet<TYPE>::_pdata = newArr;
		MySet<TYPE>::_maxsize = MySet<TYPE>::_size - 1;
		MySet<TYPE>::_size--;
	}
}

template <>
void MySet<char *>::delete_element(char *el)
{
	if (_size == 0)
	{
		cout << "а туть уже пусто...\n";
		return;
	}
	if (_size == 1)
	{
		_pdata[0] = NULL;
		--_size;
		return;
	}
	else
	{
		int pos = q_find(el) - 1;
		if (pos == -2)
		{
			cout << "Бро.... элемента |" << el << "|туть нет....\n";
			return;
		}
		for (int i = pos; i < _size - 1; i++)
		{
			_pdata[i] = _pdata[i + 1];
		}
		delete[] _pdata[--_size];
	}
}
template <class TYPE>
MySet<TYPE> MySet<TYPE>::operator=(const MySet<TYPE> v)
{

	MySet<TYPE>::_maxsize = v._maxsize;
	MySet<TYPE>::_size = v._size;
	MySet<TYPE>::_pdata = new int[v._maxsize];

	for (int i = 0; i < MySet<TYPE>::_size; i++)
	{
		MySet<TYPE>::_pdata[i] = v._pdata[i];
	}
	return *this;
}

template <>
MySet<char *> MySet<char *>::operator=(const MySet<char *> v)
{

	_maxsize = v._maxsize;
	_size = v._size;
	_pdata = new char *[v._maxsize];
	int len_word;
	for (int i = 0; i < _maxsize; i++)
	{
		if (v._pdata[i] == NULL)
		{
			len_word = 2;
		}
		else
		{
			len_word = strlen(v._pdata[i]) + 1;
		}
		delete[] _pdata[i];
		_pdata[i] = new char[len_word];
		strcpy(_pdata[i], v._pdata[i]);
	}
	return *this;
}
template <class TYPE>
bool MySet<TYPE>::operator==(MySet<TYPE> &s)
{
	if (MySet<TYPE>::_size != s._size)
		return false;
	for (int i = 0; i < MySet<TYPE>::_size; i++)
	{
		if (!is_element(s[i]))
		{
			return false;
		}
	}
	return true;
}
template <>
bool MySet<char *>::operator==(MySet<char *> &s)
{
	if (_size != s._size)
		return false;
	for (int i = 0; i < _size; i++)
	{
		if (!is_element(s[i]))
		{
			return false;
		}
	}
	return true;
}
template <class TYPE>
MySet<TYPE> &MySet<TYPE>::operator+=(MySet<TYPE> &s)
{
	for (int i = 0; i < s._size; i++)
	{
		if (!this->is_element(s[i]))
		{
			this->add_element(s[i]);
		}
	}
	return *this;
}
template <>
MySet<char *> &MySet<char *>::operator+=(MySet<char *> &s)
{
	for (int i = 0; i < s._size; i++)
	{
		if (!this->is_element(s[i]))
		{
			this->add_element(s[i]);
		}
	}
	return *this;
}
template <class TYPE>
MySet<TYPE> &MySet<TYPE>::operator-=(MySet<TYPE> &s)
{
	this->sort();
	for (int i = 0; i < s._size; i++)
	{
		if (this->is_element(s[i]))
		{
			this->delete_element(s[i]);
		}
	}
	return *this;
}

template <>
MySet<char *> &MySet<char *>::operator-=(MySet<char *> &s)
{
	this->sort();
	for (int i = 0; i < s._size; i++)
	{
		if (this->is_element(s[i]))
		{
			this->delete_element(s[i]);
		}
	}
	return *this;
}

template <class TYPE>
MySet<TYPE> &MySet<TYPE>::operator*=(MySet<TYPE> &s)
{ // есть баг с нулевым пересечением
	for (int i = 0; i < this->_size; i++)
	{
		if (!s.is_element(this->_pdata[i]))
		{
			this->delete_element(this->_pdata[i]);
		}
	}
	return *this;
}

template <>
MySet<char *> &MySet<char *>::operator*=(MySet<char *> &s)
{ // есть баг с нулевым пересечением
	for (int i = 0; i < this->_size; i++)
	{
		if (!s.is_element(this->_pdata[i]))
		{
			this->delete_element(this->_pdata[i]);
		}
	}
	return *this;
}



template <class TYPE>
bool MySet<TYPE>::is_element(TYPE el)
{

	if (MySet<TYPE>::_size == 0 || q_find(el) == -1)
		return false;
	return true;
}

template <class TYPE>
std::ostream &operator<<(std::ostream &out, MySet<TYPE> &s)
{
	int lenAll = 0;
	for (int i = 0; i < s._size; i++)
	{
		lenAll += log10(s[i]) + 4;
	}
	lenAll += 2;
	string dop(lenAll, '-');
	out << dop << endl;
	if (s[0] == -2)
	{
		out << "| ZEROVAL";
	}
	for (int i = 0; i < s._size; i++)
	{
		out << " | " << s[i];
	}
	out << " | \n";
	out << dop << endl;
	out.flush();
	return out;
}
template <>
std::ostream &operator<<(std::ostream &out, MySet<char *> &s)
{
	int lenAll = 0;
	for (int i = 0; i < s._size; i++)
	{
		lenAll += strlen(s._pdata[i]) + 3;
	}
	lenAll += 2;
	string dop(lenAll, '-');
	out << dop << endl;
	if (s[0] == NULL)
	{
		out << "| ZEROVAL";
	}
	for (int i = 0; i < s._size; i++)
	{
		out << " | " << s[i];
	}
	out << " | \n";
	out << dop << endl;
	out.flush();
	return out;
}
template <class TYPE>
MySet<TYPE> operator+(MySet<TYPE> &s1, MySet<TYPE> &s2)
{
	MySet<TYPE> res();
	res.add_element(s1[0]);
	for (int i = 1; i < s1._size; i++)
	{
		res.add_element(s1[i]);
	}
	for (int i = 0; i < s2._size; i++)
	{
		res.add_element(s2[i]);
	}
	return res;
}
template <>
MySet<char *> operator+(MySet<char *> &s1, MySet<char *> &s2)
{
	MySet<char *> res();
	res.add_element(s1[0]);
	for (int i = 1; i < s1._size; i++)
	{
		res.add_element(s1[i]);
	}
	for (int i = 0; i < s2._size; i++)
	{
		res.add_element(s2[i]);
	}
	return res;
}
template <class TYPE>
MySet<TYPE> operator-(MySet<TYPE> &s1, MySet<TYPE> &s2)
{
	MySet<int> res = s1;
	res.sort();
	for (int i = 0; i < s2._size; i++)
	{
		if (res.is_element(s2[i]))
		{
			res.delete_element(s2[i]);
		}
	}
	return res;
}
template <>
MySet<char *> operator-(MySet<char *> &s1, MySet<char *> &s2)
{
	MySet<char *> res = s1;
	res.sort();
	for (int i = 0; i < s2._size; i++)
	{
		if (res.is_element(s2[i]))
		{
			res.delete_element(s2[i]);
		}
	}
	return res;
}
template <class TYPE>
MySet<TYPE> operator*(MySet<TYPE> &s1, MySet<TYPE> &s2)
{
	MySet<int> res(); // есть баг с нулевым пересечением (решается сменой местами s1 и s в main)
	for (int i = 0; i < s1._size; i++)
	{
		if (s2.is_element(s1[i]))
		{
			res.add_element(s1[i]);
		}
	}
	return res;
}
template <>
MySet<char *> operator*(MySet<char *> &s1, MySet<char *> &s2)
{
	MySet<char *> res = s1; // есть баг с нулевым пересечением (решается сменой местами s1 и s в main)
	for (int i = 0; i < res._size; i++)
	{
		if (!s2.is_element(res[i]))
		{
			res.delete_element(res[i]);
		}
	}
	return res;
}


#endif //LAB_5_MYSET_HPP
