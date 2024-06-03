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

	std::cout << std::endl;

	MyStack<char> stack1;
	stack1.push('a');
	stack1.push('b');
	stack1.push('c');
	stack1.show();
	MyStack<char> stack2(stack1);
	stack2.show();
	MyStack<char> stack3;
	stack3 = stack2;
	stack3.show();
	return 0;
}


/*
 * 				----------------reverse order--------------->
 *
 * stack bottom -->| data |    | data |     | data |    | data |<-- stack top
 * 				   |______|    |______|     |______|    |______|
 * 				   | top  |--> | next |-->  | next |--> | tail |-->nullptr
 *
 * 				<---------------direct order-----------------
 */