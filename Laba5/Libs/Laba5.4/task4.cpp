//Выполнил Коновалюк М.А. 153502
//Определим следующую рекурсивную функцию F(n):
//	Определим функцию S(p, q) следующим образом:
//По заданным p и q необходимо вычислить S(p, q).

#include <iostream>
#include "..\StaticLib\Header.h"

int main() {
	int p, q, sum = 0;
	std::cout << "Input p & q: " << std::endl;
	while (true) {
		std::cout << "Enter a num of values: " << std::endl;
		std::cin >> p >> q;
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
	std::cout << S(p, q, sum);

	return 0;
}