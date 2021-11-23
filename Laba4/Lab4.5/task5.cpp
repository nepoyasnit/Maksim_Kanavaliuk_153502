//Задачка 5. Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	int N, count = 0, num = 0;
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
	double** arr1 = new double* [N];
	for (int i = 0; i < N; i++) {
		arr1[i] = new double[N];
	}

	double** arr2 = new double* [N];
	for (int i = 0; i < N; i++) {
		arr2[i] = new double[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr1[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr1[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr2[i][j] = 0;
			bool left = true;
			bool right = true;
			bool up = true;
			bool down = true;

			if (!i)
				up = false;
			if (i == N - 1)
				down = false;
			if (!j)
				left = false;
			if (j == N - 1)
				right = false;

			//if left element is exist
			if (left) {
				arr2[i][j] = +arr1[i][j - 1];
				count++;
			}

			//if right element is exist
			if (right) {
					arr2[i][j] += arr1[i][j + 1];
					count++;
			}

			//if down element is exist
			if (down) {
					arr2[i][j] += arr1[i + 1][j];
					count++;
					if (left) {
						arr2[i][j] += arr1[i + 1][j - 1];
						count++;
					}
					if (right) {
						arr2[i][j] += arr1[i + 1][j + 1];
						count++;
					}
			}
			
			//If up element is exist

			if (up) {
					arr2[i][j] += arr1[i - 1][j];
					count++;
					if (left) {
						arr2[i][j] += arr1[i - 1][j - 1];
						count++;
					}
					if (right) {
						arr2[i][j] += arr1[i - 1][j + 1];
						count++;
					}
			}
			arr2[i][j] /= count;
			count = 0;
		}
	}

	cout << "New matrix: " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr2[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] arr1[i];
	}
	for (int i = 0; i < N; i++) {
		delete[] arr2[i];
	}

	return 0;

}