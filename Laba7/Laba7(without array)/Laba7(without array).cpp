// Задача 1.Необходимо разработать программу для перевода чисел из
//одной системы счисления в другую.Выполнить два варианта решения
//задачи : без использования массивов и с помощью массивов.
//из девятичной в семнадцатеричную
// Выполнил Коновалюк М.А.
#include <iostream>

int main()
{
	const long double s_9 = 9;
	long double dec_i = 0;
	long double dec_d = 0;
	char ch;
	long double counter = 1;
	bool temp = true;
	while ((ch = std::cin.get()) != '\n') {
		if (ch == '.') {
			temp = false;
			continue;
		}
		if (temp) {
			dec_i *= s_9;
			dec_i += (long double)(ch - 48);
		}
		else {
			counter *= s_9;
			dec_d += (long double)(ch - 48) / counter;

		}
	}
	dec_d += dec_i;
	long long num = dec_d;
	long double ost = dec_d - num;

	std::cout << "Number in 17 system(reversed for integer value): ";

	// ПЕРЕВОЖУ В 17 СС ЦЕЛУЮ ЧАСТЬ ЧИСЛА
	int p;
	while (num) {
		p = num % 17;
		if (p == 10)
			std::cout << 'A';
		else if (p == 11)
			std::cout << 'B';
		else if (p == 12)
			std::cout << 'C';
		else if (p == 13)
			std::cout << 'D';
		else if (p == 14)
			std::cout << 'E';
		else if (p == 15)
			std::cout << 'F';
		else if (p == 16)
			std::cout << 'G';
		else if (p == 17)
			std::cout << 'H';
		else if (p == 0)
			std::cout << '0';
		else {
			std::cout << (char)(p + 48);
		}
		num /= 17;
	}
	
	// ПЕРЕВОЖУ В 17 СС ДРОБНУЮ ЧАСТЬ ЧИСЛА

	std::cout << ".";
	int c = 0;
	while (c != 9) {
		++c;
		p = ost * 17;
		ost *= 17;
		ost -= p;
		if (p == 10)
			std::cout << 'A';
		else if (p == 11)
			std::cout << 'B';
		else if (p == 12)
			std::cout << 'C';
		else if (p == 13)
			std::cout << 'D';
		else if (p == 14)
			std::cout << 'E';
		else if (p == 15)
			std::cout << 'F';
		else if (p == 16)
			std::cout << 'G';
		else if (p == 17)
			std::cout << 'H';
		else if (p == 0)
			std::cout << '0';
		else {
			std::cout << (char)(p + 48);
		}
	}

	return 0;
}
