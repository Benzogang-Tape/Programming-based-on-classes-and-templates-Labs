#include <iostream>
#include "MyStack/MyStack.hpp"


int main() {
	std::cout << "Hello, World!" << std::endl;
//	system("chcp 1251>nul");
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
	return 0;
}
