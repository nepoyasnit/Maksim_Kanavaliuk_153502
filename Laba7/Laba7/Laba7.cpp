// Задача 1.Необходимо разработать программу для перевода чисел из
//одной системы счисления в другую.Выполнить два варианта решения
//задачи : без использования массивов и с помощью массивов.
//из девятичной в семнадцатеричную
// Выполнил Коновалюк М.А.
#include <iostream>
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"

my_str Converter17(long double sum, my_str sign) {
	// ПЕРЕВОЖУ В 17 СС ЦЕЛУЮ ЧАСТЬ ЧИСЛА

	my_str res = "";
	long long num = sum;
	double ost = sum - num;
	int p;
	while (num) {
		p = num % 17;
		if (p == 10)
			res += 'A';
		else if (p == 11)
			res += 'B';
		else if (p == 12)
			res += 'C';
		else if (p == 13)
			res += 'D';
		else if (p == 14)
			res += 'E';
		else if (p == 15)
			res += 'F';
		else if (p == 16)
			res += 'G';
		else if (p == 17)
			res += 'H';
		else if (p == 0)
			res += '0';
		else {
			res += (char)(p + 48);
		}
		num /= 17;
	}

	// ПЕРЕВОРАЧИВАЮ СТРОКУ

	my_str res_i;
	for (int i = 0; i < res.size(); i++) {
		res_i += res[res.size() - i - 1];
	}
	res = "";

	// ПЕРЕВОЖУ В 17 СС ДРОБНУЮ ЧАСТЬ ЧИСЛА
	int c = 0;
	while (c != 9) {
		++c;
		p = ost * 17;
		ost *= 17;
		ost -= p;
		if (p == 10)
			res += 'A';
		else if (p == 11)
			res += 'B';
		else if (p == 12)
			res += 'C';
		else if (p == 13)
			res += 'D';
		else if (p == 14)
			res += 'E';
		else if (p == 15)
			res += 'F';
		else if (p == 16)
			res += 'G';
		else if (p == 17)
			res += 'H';
		else if (p == 0)
			res += '0';
		else {
			res += (char)(p + 48);
		}
	}
	return sign + res_i + "." + res;
}

my_str Converter10(my_str num_9) {

	// ПРОСЧИТЫВАЮ КОЛИЧЕСТВО ЧИСЕЛ ДО ТОЧКИ

	if (num_9[0] == '0') {
		return "0";
	}
	my_str sign = "";
	if (num_9[0] == '-') {
		sign += '-';
	}

	int counter1 = 0, counter2 = 0;
	long double sum = 0;
	for (int i = 0; i < num_9.size(); i++) {
		if (num_9[i] == '-')
			continue;
		if (num_9[i] == '.')
			break;
		++counter1;
	}
	--counter1;
	bool temp = false;
	for (int i = 0; i < num_9.size(); i++) {
		if (num_9[i] == '-')
			continue;
		if (num_9[i] == '.') {
			temp = true;
			continue;
		}
		if ((char)num_9[i] < 48 || (char)num_9[i] > 57) {
			std::cout << "Wrong input! Please, try again!";
			break;
		}
		if (!temp) {
			sum += ((long double)num_9[i] - 48) * pow(9, counter1);
			--counter1;
		}
		else {
			--counter2;
			sum += ((long double)num_9[i] - 48) * pow(9, counter2);
		}
	}
	return Converter17(sum, sign);
}

int main()
{
	my_str num_9;
	std::cin >> num_9;
	std::cout << "Result: " << Converter10(num_9) << '\n';
	return 0;
}
