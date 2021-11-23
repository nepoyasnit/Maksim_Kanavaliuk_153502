//Задачка 9. Выполнил Коновалюк М.А.
#include <iostream>

using namespace std;

int main() {
	srand(time(0));
	int** A = 0;
	int** B = 0;
	int** AB = 0;
	int N;
	while (true) {
		cout << "Enter a num of values: " << endl;
		cin >> N;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "That input is invalid. Try again" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}
	A = (int**)malloc(N * 4);
	B = (int**)malloc(N * 4);
	AB = (int**)malloc(N * 4);

	for (int i = 0; i < N; i++) {
		A[i] = (int*)malloc(N * 4);
		B[i] = (int*)malloc(N * 4);
		AB[i] = (int*)malloc(N * 4);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cin >> A[i][j] >> B[i][j];
			A[i][j] = rand() % 100;
			B[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[i][j] = 0;
			for (int k = 0; k < N; k++)
				AB[i][j] += A[i][k] * B[k][j];
			//Вывод значения элемента на экран:
			cout << AB[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		free(A[i]);
		free(B[i]);
		free(AB[i]);
	}
	free(A);
	free(B);
	free(AB);

	return 0;
}