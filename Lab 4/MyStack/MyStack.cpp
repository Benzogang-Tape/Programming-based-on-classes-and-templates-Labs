#include "MyStack.hpp"

void Multipliers(int n, MyStack<int> &stack)
{
	while (!stack.empty()) {
		stack.pop();
	}
	int sign = n < 0 ? -1 : 1;
	n = abs(n);
	if (n == 0) {
		stack.push(0);
	}
	if (n == 1) {
		stack.push(1 * sign);
	}
	int i{2}, count{};
	while ((n > 2) and (i <= n)) {
		if (n % i == 0) {
			if (count == 0) {
				stack.push(i * sign);
			} else {
				stack.push(i);
			}
			count++;
			n /= i;
			i = 1;
		}
		i++;
	}
	if (n == 2)
		stack.push(2);
}