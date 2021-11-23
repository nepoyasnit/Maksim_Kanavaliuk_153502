//Задачка 3. Дана целочисленная матрица размером N. Найти сумму наименьших элементов ее нечетных строк и наибольших элементов ее четных строк
//Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	int N;
	while (true) {
		cout << "Enter a num of values: " << endl;
		cin >> N;
		if (cin.get() != '\n') {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "That input is invalid. Try again" << endl;
		}
		else {
			break;
		}
	}

	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = rand() % 1000;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	int sum1 = 0, sum2 = 0;
	int min = 1000000;
	int max = -1000000;

	//СУММА МИНИМАЛЬНЫХ
	for (int i = 0; i < N; i += 2) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
		sum1 += min;
	}

	//СУММА МАКСИМАЛЬНЫХ
	for (int i = 1; i < N; i += 2) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
		sum2 += max;
	}

	cout << "Sum of minimal = " << sum1 << endl;
	cout << "Sum of maximal = " << sum2 << endl;

	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}

	return 0;
}