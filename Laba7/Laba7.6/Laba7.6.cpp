﻿//Задание 6. Пусть S(x) - это сумма цифр числа x, записанного в десятичной системе счисления. 
//Например, S(5) = 5, S(10) = 1, S(322) = 7.
//Мы будем называть х интересным, если S(x + 1) < S(x). В каждом тесте вам будет дано одно число n. 
//Ваша задача - посчитать колво чисел х таких, что 1 <= x <= n и х - интересное.
//Выполнил Коновалюк М.А.
#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		long long n;
		std::cin >> n;
		
		std::cout << (n + 1) / 10 << std::endl;
	}

	return 0;
}
