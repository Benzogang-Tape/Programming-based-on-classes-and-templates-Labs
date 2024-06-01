#ifndef LAB_4_MYSTACK_HPP
#define LAB_4_MYSTACK_HPP

#include <iostream>
#include <cmath>
using namespace std;

template <class INF, class FRIEND>
class ListNode
{
private:
	INF d;
	ListNode *next;
	ListNode() { next = nullptr; }
	ListNode(ListNode &tmp);
	friend FRIEND;
};


template <class INF>
class MyStack
{
	typedef class ListNode<INF, MyStack<INF>> Node;
	Node *top;

public:
	MyStack();
	~MyStack();
	MyStack(MyStack &tmp);
	bool empty();
	bool push(INF n);
	bool pop();
	INF top_inf();
	MyStack<INF> operator=(MyStack<INF> tmp);
	void show();
	void showReverse();
};

template <class INF>
bool MyStack<INF>::empty() {
	if (top == nullptr)
		return true;
	else
		return false;
}

template <class INF>
MyStack<INF>::MyStack() {
	top = nullptr;
}

template <class INF>
MyStack<INF>::~MyStack() {
	delete[] top;
}

template <class INF>
inline MyStack<INF>::MyStack(MyStack &tmp)
{
	top = nullptr;
	top = new Node{};
	top->d = tmp.top->d;

	Node *cur = tmp.top;
	Node *to_cur = top;

	while (cur->next != nullptr)
	{
		to_cur->next = new Node{};
		to_cur->next->d = cur->next->d;
		to_cur = to_cur->next;
		cur = cur->next;
	}
}

template <class INF>
bool MyStack<INF>::push(INF n)
{
	if (empty())
	{
		top = new Node{};
		top->d = n;
		return 0;
	}
	Node *cur = top;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = new Node{};
	cur->next->d = n;
	return 1;
}

template <class INF>
inline bool MyStack<INF>::pop(void)
{
	if (top->next == nullptr)
	{
		cout << "\n???????? head, ????????\n";
		top = nullptr;
		return 0;
	}

	Node *cur = top;
	while (cur->next->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = nullptr;
	delete cur->next;
	return 1;
}

template <class INF>
INF MyStack<INF>::top_inf(void)
{
	return top->d;
}
template <class INF>
inline MyStack<INF> MyStack<INF>::operator=(MyStack<INF> tmp)
{

	top = nullptr;
	top = new Node{};
	top->d = tmp.top->d;

	Node *cur = tmp.top;
	Node *to_cur = top;

	while (cur->next != nullptr)
	{
		to_cur->next = new Node{};
		to_cur->next->d = cur->next->d;
		to_cur = to_cur->next;
		cur = cur->next;
	}
	return *this;
}
template <class INF>
inline void MyStack<INF>::showReverse(void)
{
	Node *cur = top;
	int i = 0;
	while (cur != nullptr)
	{
		if (i)
			cout << "* ";
		cout << cur->d << " ";
		cur = cur->next;
		i++;
	}
}
template <class INF>
inline void MyStack<INF>::show(void)
{
	Node *last = top;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	cout << last->d;
	if (last != top)
	{
		while (true)
		{
			Node *beforeLast = top;
			while (beforeLast->next != last)
			{
				beforeLast = beforeLast->next;
			}
			cout << " * " << beforeLast->d;
			last = beforeLast;

			if (last == top)
			{
				break;
			}
		}
	}
}

void Multipliers(int n, MyStack<int> &stack);


#endif //LAB_4_MYSTACK_HPP
