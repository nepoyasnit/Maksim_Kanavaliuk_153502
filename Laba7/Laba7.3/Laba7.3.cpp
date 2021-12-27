//Задание 3. Осуществить сложение чисел.Разработать функции для
//выполнения операции сложения.Предусмотреть ввод положительных и
//отрицательных чисел. Найдите сумму двоичных чисел, заданных в естественной
//форме.Сложение выполните в дополнительном коде.Ответ
//выразите в естественной форме
//Выполнил Коновалюк М.А.
#include <iostream>
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"

my_str new_code(my_str& s) {
	if (s[0] == '0')
		return s;
	else {
		for (int i = 2; i < s.size(); i++) {
			if (s[i] == '0')
				s[i] = '1';
			else if (s[i] == '1')
				s[i] = '0';
		}
		int brain = 1;
		for (int i = s.size() - 1; i > 1; i--) {
			if (s.ctoi(s[i]) && brain) {
				s[i] = '0';
			}
			else if (brain && !s.ctoi(s[i])) {
				s[i] = '1';
				break;
			}
		}
		return s;
	}
}

my_str Sum(my_str s1, my_str s2) {
	s1.reverse();
	s2.reverse();
	int brain = 0;
	my_str sum;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '.') {
			sum += '.';
		}
		else {
			int num1 = s1[i] - '0';
			int num2 = s2[i] - '0';
			sum += (num1 + num2 + brain) % 2 + '0';
			brain = (num1 + num2) / 2;
		}
	}
	
	sum.reverse();
	return sum;
}

my_str Solver(my_str string1, my_str string2) {
	string1.reverse();
	string2.reverse();
	int k = 0, counter1 = 0, counter2 = 0;

	my_str str1, str2;
	while (string1[k] != '.' && string1[k] != ',') {
		str1 += string1[k];
		++k;
	}
	k = 0;
	while (string2[k] != '.' && string2[k] != ',') {
		str2 += string2[k];
		++k;
	}

	if (str1.size() > str2.size()) {
		while (str1.size() != str2.size()) {
			str2 += '0';
		}
		str1 += string1[string1.size() - 1];
		str2 += string2[string2.size() - 1];
	}
	else if (str2.size() > str1.size()) {
		while (str1.size() != str2.size()) {
			str1 += '0';
		}
		str1 += '.';
		str2 += '.';
		str1 += string1[string1.size() - 1];
		str2 += string2[string2.size() - 1];
	}
	else {
		str1 += '.';
		str2 += '.';
		str1 += string1[string1.size() - 1];
		str2 += string2[string2.size() - 1];
	}

	str1.reverse();
	str2.reverse();

	new_code(str1);
	new_code(str2);

	//std::cout << "s1 " << str1 << " s2 " << str2 << '\n';
	my_str res = Sum(str1, str2);
	return res;
}

int main()
{
	my_str string1;
	my_str string2;

	std::cin >> string1;
	std::cin >> string2;

	std::cout << Solver(string1, string2);

	return 0;
}