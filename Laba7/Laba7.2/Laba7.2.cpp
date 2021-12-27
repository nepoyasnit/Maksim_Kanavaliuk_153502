//Задача 2. Перевести числа.Предусмотреть ввод положительных и
//отрицательных чисел.Из прямого кода в дополнительный
//Выполнил Коновалюк М.А.

#include <iostream>
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"

my_str new_code(my_str s) {
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


int main()
{
	my_str str_1; // ПРЯМОЙ КОД
	std::cin >> str_1;
	std::cout << new_code(str_1);

	return 0;
}
