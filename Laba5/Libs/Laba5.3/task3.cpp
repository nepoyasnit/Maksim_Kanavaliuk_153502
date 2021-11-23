//Выполнил Коновалюк М.А. 153502
//Дан двумерный динамический массив целых чисел А размерностью n & k .
//Размерность массива(n = 5, k = 6) ввести с клавиатуры.Значения элементов массива
//ввести с клавиатуры.Создать динамический массив из элементов, расположенных на
//главной диагонали матрицы и имеющих четное значение.Вычислить произведение
//элементов динамического массива.
//Созданный массив и результат произведения вывести на экран.
//Использовать функции.

#include <iostream>

int main() {
	int n, k;
	int counter = 0;
	int proiz = 1;
	while (true) {
		std::cout << "Enster a num of values: " << std::endl;
		std::cin >> n >> k;
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
	int** B = new int* [n];
	int* new_arr = new int[n];
	for (int i = 0; i < n; i++) {
		B[i] = new int[k];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			std::cin >> B[i][j];
			if (i == j && B[i][j] % 2 == 0) {
				new_arr[counter] = B[i][i];
				proiz *= B[i][i];
				++counter;
			}
		}
	}

	std::cout << "New array: ";

	for (int i = 0; i < counter; i++) {
		std::cout << new_arr[i] << " ";
	}

	std::cout << std::endl << "Proiz: " << proiz << std::endl;

	for (int i = 0; i < n; i++) {
		delete[] B[i];
	}

	delete[] new_arr;


	return 0;
}