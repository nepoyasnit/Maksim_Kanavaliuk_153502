//Задачка 4. Элемент матрицы называется локальным минимумом, если он строго меньше всех имеющихся у него соседей. Соседями элемента ajj в матрице назовем элементы akg, где i-1<=k<=i+1, j-1<=g<=j+1, (k,g) != (i,j)
//Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	int N, count = 0, num = 0;
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
			arr[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

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

			bool prov1 = false, prov2 = false, prov3 = false, prov4 = false, prov5 = false, prov6 = false, prov7 = false, prov8 = false;

			if (left) {
				prov1 = arr[i][j] < arr[i][j - 1];
				count++;
			}
			if (right) {
				prov2 = arr[i][j] < arr[i][j + 1];
				count++;
			}
			if (up) {
				prov3 = arr[i][j] < arr[i - 1][j];
				count++;
				if (left) {
					prov5 = arr[i][j] < arr[i - 1][j - 1];
					count++;
				}
				if (right) {
					prov6 = arr[i][j] < arr[i - 1][j + 1];
					count++;
				}
			}
			if (down) {
				prov4 = arr[i][j] < arr[i + 1][j];
				count++;
				if (left) {
					prov7 = arr[i][j] < arr[i + 1][j - 1];
					count++;
				}
				if (right) {
					prov8 = arr[i][j] < arr[i + 1][j + 1];
					count++;
				}

			}

			if (prov1 + prov2 + prov3 + prov4 + prov5 + prov6 + prov7 + prov8 == count) {
				cout << "The value " << arr[i][j] << " is a local minimum!" << endl;
				num++;
			}
			count = 0;
		}
	}
	if (!num)
		cout << "This matrix hasn't a local minimums";

	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}

	return 0;

}