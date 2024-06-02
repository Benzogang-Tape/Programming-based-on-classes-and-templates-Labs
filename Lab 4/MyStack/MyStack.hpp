#ifndef LAB_4_MYSTACK_HPP
#define LAB_4_MYSTACK_HPP

#include <iostream>


template <class INF, class FRIEND>
class ListNode
{
private:
	INF d;
	ListNode *next;
	ListNode() { next = nullptr; d = INF{};}
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
	MyStack(const MyStack &tmp);
	bool empty();
	bool push(INF n);
	bool pop();
	INF top_inf();
	MyStack<INF>& operator=(const MyStack<INF>& tmp);
	void show();
	void showReverse();
};

template <class INF>
bool MyStack<INF>::empty() {
	return top == nullptr;
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
inline MyStack<INF>::MyStack(const MyStack &tmp) {
	top = nullptr;
	top = new Node{};
	top->d = tmp.top->d;

	Node *cur {tmp.top}, *toCur{top};

	while (cur->next != nullptr) {
		toCur->next = new Node{};
		toCur->next->d = cur->next->d;
		toCur = toCur->next;
		cur = cur->next;
	}
}

template <class INF>
bool MyStack<INF>::push(INF n) {
	if (empty()) {
		top = new Node{};
		top->d = n;
		return false;
	}
	Node *cur{top};
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = new Node{};
	cur->next->d = n;
	return true;
}

template <class INF>
bool MyStack<INF>::pop() {
	if (top->next == nullptr) {
		delete top;
		top = nullptr;
		return false;
	}

	Node *cur{top};
	while (cur->next->next != nullptr) {
		cur = cur->next;
	}
	delete cur->next;
	cur->next = nullptr;
	return true;
}

template <class INF>
INF MyStack<INF>::top_inf() {
	return top->d;
}
template <class INF>
inline MyStack<INF>& MyStack<INF>::operator=(const MyStack<INF>& tmp) {
	if (&tmp == this) {
		return *this;
	}
	top = nullptr;
	top = new Node{};
	top->d = tmp.top->d;

	Node *cur {tmp.top}, *toCur{top};

	while (cur->next != nullptr) {
		toCur->next = new Node{};
		toCur->next->d = cur->next->d;
		toCur = toCur->next;
		cur = cur->next;
	}
	return *this;
}
template <class INF>
inline void MyStack<INF>::showReverse() {
	const Node* cur{top};
	bool firstElem{};
	while (cur != nullptr) {
		if (firstElem) {
			std::cout << "* ";
		}
		std::cout << cur->d << " ";
		cur = cur->next;
		firstElem = true;
	}
	std::cout << std::endl;
}
template <class INF>
inline void MyStack<INF>::show() {
	const Node *last{top};
	while (last->next != nullptr) {
		last = last->next;
	}
	std::cout << last->d;
	if (last != top) {
		for (;;) {
			Node *preLast = top;
			while (preLast->next != last) {
				preLast = preLast->next;
			}
			std::cout << " * " << preLast->d;
			last = preLast;

			if (last == top) {
				break;
			}
		}
	}
	std::cout << std::endl;
}

void Multipliers(int num, MyStack<int> &stack);


#endif //LAB_4_MYSTACK_HPP
