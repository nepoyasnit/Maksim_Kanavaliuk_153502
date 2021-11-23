#include "pch.h"
#include <iostream>

int Sum(int n) {
	if (n % 2 != 0) {
		return n;
	}
	else {
		while (n % 2 == 0)
			n /= 2;
		return n;
	}
}

int main() {
	int n, sum = 0;
	std::cout << "Input n: " << std::endl;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += Sum(i);
	}

	std::cout << sum;

	return 0;
}