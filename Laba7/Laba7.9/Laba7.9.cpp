﻿//Задача 9. Вчера на уроке математики Саша(возможно Богом данный) узнал
//о том, что иногда полезно использовать вместо десятичной системы
//счисления какую - нибудь другую.Однако, учительница(как иронично) не
//объяснила, почему в системе счисления по основанию b в качестве цифр
//выбирают числа от 0 до b - 1. Немного подумав, Саша понял, что можно
//выбирать и другие наборы цифр.Например, вместо троичной системы
//счисления можно рассмотреть систему счисления, где вместо обычных цифр
//0, 1, 2 есть цифры 1, 2 и 3. Саша заинтересовался вопросом, а как перевести
//число n в эту систему счисления ? Например, число 7 в этой системе
//записывается как 21, так как 7 = 2∙3 + 1, а число 22 записывается как 211, так
//как 22 = 2 ∙ 9 + 1 ∙ 3 + 1.
//Выполнил Коновалюк М.А.
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"
#include <iostream>

my_str Solver(int n) {
	int temp = 1;
	int length = 0;
	while (n / temp > 0) {
		temp *= 3;
		++length;
	}

	temp /= 3;
	int* arr = new int[length];
	int position = 0;
	my_str result = "";

	while (temp) {
		arr[position] = n / temp;
		n %= temp;
		temp /= 3;
		int l = position;
		while (arr[l] == 0 && l != 0) {
			arr[l] = 3;
			--l;
			--arr[l];
		}
		++position;
	}

	for (int i = 0; i < length; i++) {
		if (arr[i] == 0 && i != 0)
			break;
		else if (arr[i] != 0) {
			result += arr[i] + '0';
		}
	}

	delete[] arr;

	return result;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << Solver(n);

	return 0;
}
