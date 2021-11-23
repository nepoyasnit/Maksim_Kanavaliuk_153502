//Задачка 10. Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int** A = 0;
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
			cin.ignore(32767, '\n');
			break;
		}
	}
	A = (int**)malloc(N * 4);
	for (int i = 0; i < N; i++) {
		A[i] = (int*)malloc(N * 4);
	}
	if (N % 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = 1 + ((i + j + 1 + (N - 1) / 2) % N) * N + ((i + 1 + 2 * (j + 1)) % N);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		free(A[i]);
	}
	free(A);

    return 0;
}