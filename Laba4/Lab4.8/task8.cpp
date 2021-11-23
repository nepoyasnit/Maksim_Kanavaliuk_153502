//Задачка 8. Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	int N, count = 0;
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
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	
	for (int i = 0; i < N; i++) {
		if (arr[i] == min) {
			for (int j = i + 1; j < N; j++) {
				if (arr[j] == max)
					break;
				arr[j] = 0;		
				count++;
			}
			break;
		}
		if (arr[i] == max) {
			for (int j = i + 1; j < N; j++) {
				if (arr[j] == min)
					break;
				arr[j] = 0;
			}
			break;
		}
	}
	int* prov_arr = new int[count];
	if (count > N / 2) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i]) {
				prov_arr[temp] = arr[i];
				temp++;
			}

		}
		for (int i = 0; i < N; i++) {
			cout << prov_arr[i] << " ";
		}
	}

	else {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
	}

	delete[] arr;

	return 0;
}