//Задачка 6. Выполнил Коновалюк М.А.
#include <iostream> 

using namespace std;

int main() {
	int N, M;
	while (true) {
		cout << "Enter N & M: " << endl;
		cin >> N >> M;
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

	int** arr1 = new int* [N];
	for (int i = 0; i < N; i++) {
		arr1[i] = new int[M];
	}

	int** arr2 = new int* [N];
	for (int i = 0; i < N; i++) {
		arr2[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr1[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << arr1[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			bool left = true;
			bool up = true;

			if (!i)
				up = false;
			if (!j)
				left = false;

			arr2[i][j] = arr1[i][j];

			//if left element is exist
			if (left) {
				for (int temp = 0; temp < j; temp++) {
					if (arr1[i][temp] > arr2[i][j])
					{
						arr2[i][j] = arr1[i][temp];
					}
				}
			}

			//If up element is exist

			if (up) {
				for (int temp = 0; temp < i; temp++) {
					if (arr1[temp][j] > arr2[i][j])
					{
						arr2[i][j] = arr1[temp][j];
					}
				}
			}

			if (left && up) {
				for (int temp1 = 0; temp1 < i; temp1++) {
					for (int temp2 = 0; temp2 < j; temp2++) {
						if (arr1[temp1][temp2] > arr2[i][j])
						{
							arr2[i][j] = arr1[temp1][temp2];
						}
					}
				}
			}
		}
	}

	cout << "New matrix: " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
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