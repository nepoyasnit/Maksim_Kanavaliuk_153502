//Задачка 2. Найти минимальный среди элементов, лежащих ниже главной диагонали
//Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>

using namespace std;

const int N = 4;
const int M = 4;

int main() {
	srand(time(0));
	int arr[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = rand();
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int min = 1000000;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i / 2 + 1; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
	}

	

	cout << "Minimal value: " << min << endl;

	return 0;
}
