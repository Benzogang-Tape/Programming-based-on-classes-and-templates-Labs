#include "MyStack.hpp"

void Multipliers(int num, MyStack<int> &stack)
{
	while (!stack.empty()) {
		stack.pop();
	}
	int sign = num < 0 ? -1 : 1;
	num = abs(num);
	if (num == 0) {
		stack.push(0);
	}
	if (num == 1) {
		stack.push(1 * sign);
	}
	int i{2}, count{};
	while ((num > 2) and (i <= num)) {
		if (num % i == 0) {
			if (count == 0) {
				stack.push(i * sign);
			} else {
				stack.push(i);
			}
			count++;
			num /= i;
			i = 1;
		}
		i++;
	}
	if (num == 2)
		stack.push(2);
}