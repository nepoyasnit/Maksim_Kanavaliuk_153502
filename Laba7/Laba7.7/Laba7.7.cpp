//Задание 7. Необходимо разработать программу, которая проверяет, делится
//ли введенное пользователем число на заданное простое.Программа не
//должна содержать операций умножения, деления, вычитания(в том числе
//взятия остатка от деления).Рекомендуется использовать побитовые
//операции.Для каждого варианта нужно проверить делимость на 3 простых
//числа.Проверять можно по отдельности(сначала получить ответ для
//первого, затем для второго, затем для третьего).
//10) 3, 47, 197
//Выполнил Коновалюк М.А.

#include <iostream>

int main()
{
	long long in;
	std::cout << "Input the num: " << std::endl;
	std::cin >> in;

	bool isDiv = false;
	long long var = 0;
	long long counter1, counter2, counter3;

	std::cout << "Input three deviders: " << std::endl;
	std::cin >> counter1 >> counter2 >> counter3;

	long long tmp = in;
	while (tmp >= var) {
		while (!(tmp & 1))
			tmp >>= 1;
		if (tmp == var) {
			isDiv = true;
			break;
		}
		var += counter1;
	}
	if (isDiv) {
		std::cout << "The num devides 3" << std::endl;
	}
	else {
		std::cout << "The num don't devides 3" << std::endl;
	}

	isDiv = false;
	tmp = in;
	var = 0;
	while (tmp >= var) {
		while (!(tmp & 1))
			tmp >>= 1;
		if (tmp == var) {
			isDiv = true;
			break;
		}
		var += counter2;
	}
	if (isDiv) {
		std::cout << "The num devides 47" << std::endl;
	}
	else {
		std::cout << "The num don't devides 47" << std::endl;
	}

	isDiv = false;
	tmp = in;
	var = 0;
	while (tmp >= var) {
		while (!(tmp & 1))
			tmp >>= 1;
		if (tmp == var) {
			isDiv = true;
			break;
		}
		var += counter3;
	}
	if (isDiv) {
		std::cout << "The num devides 197" << std::endl;
	}
	else {
		std::cout << "The num don't devides 197" << std::endl;
	}

	return 0;
}