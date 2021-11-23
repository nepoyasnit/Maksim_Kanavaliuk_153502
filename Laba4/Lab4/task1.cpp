//Задачка 1. Определить, симметричен ли массив, т.е. читается ли он одинаково слева направо и справа налево
//Выполнил Коновалюк М.А. 153502
#include <iostream>

using namespace std;

const int k = 5;

int main() {
	int i, j;
	double arr[k];
	int count = 0;
	for (i = 0; i < k; i++) {
		cout << "Enter a num: " << endl;
		cin >> arr[i];
	}
	for (i = 0, j = k - 1; i < k / 2; i++, j--) {
		if (arr[i] == arr[j]) {
			count++;
		}
	}
	if (count == k / 2) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}