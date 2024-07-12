#ifndef LAB_5_MYVECTOR_HPP
#define LAB_5_MYVECTOR_HPP


#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_SIZE = 5;
const int WORD_SIZE = 50;

template <class TYPE>
class MyVector
{
public:
	MyVector(int maxsz = MAX_SIZE);

	MyVector(const MyVector<TYPE> &v);

	~MyVector();

	void add_element(TYPE el);

	bool delete_element(int num);

	TYPE operator[](int i);

	void sort();

	int Size() { return _size; }

	int Maxsize() { return _maxsize; }

	int find(TYPE el);

	void mySwap(TYPE &a, TYPE &b);

	MyVector<TYPE> &operator=(const MyVector<TYPE> &v);

	template <class U>
	friend std::ostream &operator<<(std::ostream &out, MyVector<U> &v);

protected:
	int _maxsize;
	int _size;
	TYPE *_pdata;
	void _resize();
};
//-----------------------------CHAR *-----------------------------------------

template <class TYPE>
void MyVector<TYPE>::_resize()
{
	if (_size + 1 > _maxsize)
	{
		TYPE *newPdata = new TYPE[_maxsize * 2];
		for (int i = 0; i < _size; i++)
		{
			newPdata[i] = _pdata[i];
		}
		_pdata = newPdata;
		_maxsize *= 2;
	}
	else if (_size - 1 < _maxsize / 4)
	{
		int newLen = (_maxsize / 2 > MAX_SIZE ? _maxsize / 2 : MAX_SIZE);
		TYPE *newPdata = new TYPE[newLen];
		for (int i = 0; i < _size; i++)
		{
			newPdata[i] = _pdata[i];
		}
		_pdata = newPdata;
		_maxsize = newLen;
	}
	else
	{
	}
}
template <>
void MyVector<char *>::_resize()
{
	if (_size + 1 > _maxsize)
	{
		char **newPdata = new char *[_maxsize * 2];
		for (int i = 0; i < _maxsize * 2; i++)
		{
			newPdata[i] = new char[WORD_SIZE];
		}
		for (int i = 0; i < _size; i++)
		{
			strcpy(newPdata[i], _pdata[i]);
		}
		_pdata = newPdata;
		_maxsize *= 2;
	}
	else if (_size - 1 < _maxsize / 4)
	{
		int newLen = (_maxsize / 2 > MAX_SIZE ? _maxsize / 2 : MAX_SIZE);
		char **newPdata = new char *[newLen];
		for (int i = 0; i < newLen; i++)
		{
			newPdata[i] = new char[WORD_SIZE];
		}
		for (int i = 0; i < _size; i++)
		{
			strcpy(newPdata[i], _pdata[i]);
		}
		_pdata = newPdata;
		_maxsize = newLen;
	}
	else
	{
	}
}

template <class TYPE>
void MyVector<TYPE>::mySwap(TYPE &a, TYPE &b)
{
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}
template <>
void MyVector<char *>::mySwap(char *&a, char *&b)
{
	char *tmp = new char[WORD_SIZE];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
	delete[] tmp;
}

template <class TYPE>
MyVector<TYPE>::MyVector(int maxsz)
{
	_size = 0;
	_maxsize = maxsz;
	_pdata = new int[_maxsize];
}
template <>
MyVector<char *>::MyVector(int maxsz)
{
	_size = 0;
	_maxsize = maxsz;
	_pdata = new char *[_maxsize];
	int len = 5;
	for (int i = 0; i < maxsz; i++)
	{
		_pdata[i] = new char[len];
		_pdata[i] = NULL;
	}
}

template <class TYPE>
MyVector<TYPE>::MyVector(const MyVector<TYPE> &v)
{
	_maxsize = v._maxsize;
	_size = v._size;
	_pdata = new int[v._maxsize];
	for (int i = 0; i < _size; i++)
	{
		_pdata[i] = v._pdata[i];
	}
}

template <>
MyVector<char *>::MyVector(const MyVector<char *> &v)
{
	_maxsize = v._maxsize;
	_size = v._size;
	_pdata = new char *[v._maxsize];
	int len_word;
	for (int i = 0; i < _maxsize; i++)
	{
		if (v._pdata[i] == NULL)
		{
			len_word = 5;
		}
		else
		{
			len_word = strlen(v._pdata[i]) + 1;
		}
		delete[] _pdata[i];
		_pdata[i] = new char[len_word];
		strcpy(_pdata[i], v._pdata[i]);
	}
}
template <class TYPE>
TYPE MyVector<TYPE>::operator[](int i)
{
	if (i < 0 || i > _maxsize)
	{
		throw "OutOfRange";
	}
	return _pdata[i]; // СДЕЛАТЬ ПРОВЕРКУ НА ИНДЕКС
}
template <>
char *MyVector<char *>::operator[](int i)
{
	if (i < 0 || i > _maxsize)
	{
		throw "OutOfRange";
	}
	if (_size != 0)
	{
		return _pdata[i];
	}
	return NULL;
}

template <class TYPE>

MyVector<TYPE>::~MyVector()
{
	delete[] _pdata;
}
template <>
MyVector<char *>::~MyVector()
{
	int size = _maxsize;
	for (int i = 0; i < size; i++)
	{

		delete[] _pdata[i];
	}
	delete[] _pdata;
}

template <class TYPE>
void MyVector<TYPE>::add_element(TYPE el)
{
	_resize();
	if (_pdata[0] == -2)
	{
		_pdata[0] = el;
	}
	else
	{
		_pdata[_size] = el;
		_size++;
	}
}
template <>
void MyVector<char *>::add_element(char *el)
{
	_resize();
	if (_pdata[0] == NULL)
	{
		_pdata[0] = el;
	}
	else
	{
		delete[] _pdata[_size];
		_pdata[_size] = new char[strlen(el) + 1];
		strcpy(_pdata[_size], el);
		_size++;
	}
}
template <class TYPE>
bool MyVector<TYPE>::delete_element(int num)
{
	if (_size == 0)
	{
		cout << "а туть уже пусто...\n";
		return 0;
	}
	if (_size == 1)
	{
		_pdata[0] = -2;
		--_size;
		return 1;
	}
	else
	{
		int *newPdata = new int[_size - 1];
		for (int i = num - 1; i < _size - 1; i++)
		{
			_pdata[i] = _pdata[i + 1];
		}
		for (int i = 0; i < _size - 1; i++)
		{
			newPdata[i] = _pdata[i];
		}
		_pdata = newPdata;
		_maxsize = _size - 1;
		_size--;
		return 1;
	}
}

template <>
bool MyVector<char *>::delete_element(int num)
{
	if (_size == 0)
	{
		cout << "а туть уже пусто...\n";
		return 0;
	}
	if (_size == 1)
	{
		_pdata[0] = NULL;
		--_size;
		return 1;
	}
	else
	{
		_resize();
		for (int i = num - 1; i < _size - 1; i++)
		{
			_pdata[i] = _pdata[i + 1];
		}
		if (_size > 0)
		{
			delete[] _pdata[--_size];
		}
		return 1;
	}
}
template <class TYPE>
void MyVector<TYPE>::sort()
{
	for (int i = 0; i < _size; i++)
	{
		bool flag = true;
		for (int j = 0; j < _size - 1; j++)
		{
			if (_pdata[j] > _pdata[j + 1])
			{
				mySwap(_pdata[j], _pdata[j + 1]);
				flag = false;
			}
		}
		if (flag)
			break;
	}
}
template <>
void MyVector<char *>::sort()
{
	for (int i = 0; i < _size; i++)
	{
		bool flag = true;
		for (int j = 0; j < _size - 1; j++)
		{
			if (strcmp(_pdata[j], _pdata[j + 1]) > 0)
			{
				mySwap(_pdata[j], _pdata[j + 1]);
				flag = false;
			}
		}
		if (flag)
			break;
	}
}
template <class TYPE>
int MyVector<TYPE>::find(TYPE el)
{
	for (int i = 0; i < _size; i++)
	{
		if (_pdata[i] == el)
		{
			return i + 1;
		}
	}
	cout << "Чет, брат, такого значения нет\n";
	return -1;
}
template <>
int MyVector<char *>::find(char *el)
{
	for (int i = 0; i < _size; i++)
	{
		if (strcmp(_pdata[i], el) == 0)
		{
			return i + 1;
		}
	}
	cout << "Чет, брат, такого значения нет\n";
	return -1;
}

template <class TYPE>
MyVector<TYPE> &MyVector<TYPE>::operator=(const MyVector<TYPE> &v)
{
	_maxsize = v._maxsize;
	_size = v._size;
	if (_pdata){
		delete[] _pdata;
	}
	_pdata = new int[v._size];
	for (int i = 0; i < _size; i++)
	{
		_pdata[i] = v._pdata[i];
	}
	return *this;
}

template <>
MyVector<char *> &MyVector<char *>::operator=(const MyVector<char *> &v)
{
	_maxsize = v._maxsize;
	_size = v._size;
	_pdata = new char *[v._size];
	int len_word;
	for (int i = 0; i < _size; i++)
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
std::ostream &operator<<(std::ostream &out, MyVector<TYPE> &v)
{

	int lenAll = 0;
	for (int i = 0; i < v._size; i++)
	{
		lenAll += log10(v[i]) + 4;
	}
	lenAll += 2;
	string dop(lenAll, '-');
	out << dop << endl;
	if (v[0] == -2)
	{
		out << "| ZEROVAL";
	}
	for (int i = 0; i < v._size; i++)
	{
		out << " | " << v[i];
	}
	out << " | \n";
	out << dop << endl;
	out.flush();
	return out;
}
template <>
std::ostream &operator<<(std::ostream &out, MyVector<char *> &v)
{
	int lenAll = 0;
	for (int i = 0; i < v._size; i++)
	{
		lenAll += strlen(v._pdata[i]) + 3;
	}
	lenAll += 2;
	string dop(lenAll, '-');
	out << dop << endl;
	if (v[0] == NULL)
	{
		out << "| ZEROVAL";
	}
	for (int i = 0; i < v._size; i++)
	{
		out << " | " << v[i];
	}
	out << " | \n";
	out << dop << endl;
	out.flush();
	return out;
}

#endif //LAB_5_MYVECTOR_HPP
