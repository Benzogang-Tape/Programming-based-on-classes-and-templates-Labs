#include <iostream>
#include "MyStack/MyStack.hpp"


int main() {
	int num{};
	std::cin >> num;
	MyStack<int> stack;
	Multipliers(num, stack);
	MyStack<int> stackCopy(stack);
	stackCopy.show();
	stack.showReverse();
	return 0;
}


/*
	MyStack<char> stack;
	stack.push('a');
	stack.push('b');
	stack.push('c');
	MyStack<char> stack2(stack);
	stack.show();
	cout << endl;
	stack2.show();
	cout << endl;
	MyStack<char> stack3;
	stack3 = stack;
	stack3.show();
	cout << endl;
 */
