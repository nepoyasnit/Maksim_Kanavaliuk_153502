//Выполнил Коновалюк М.А.
//Пусть f(n) - наибольший нечетный делитель натурального числа n.По заданному
//натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).

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
	while (true) {
		std::cout << "Enster a num of values: " << std::endl;
		std::cin >> n;
		if (std::cin.get() != '\n') {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid. Try again" << std::endl;
		}
		else {
			std::cin.ignore(32767, '\n');
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum += Sum(i);
	}

	std::cout << sum;

	return 0;
}