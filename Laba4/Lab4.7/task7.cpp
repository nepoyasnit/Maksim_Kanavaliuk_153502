//Задачка 7. Выполнил Коновалюк М.А.
#include <iostream>

using namespace std;

int main() {
	unsigned int N, i;
	while (true) {
		cout << "Enter N & i: " << endl;
		cin >> N >> i;
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
	int temp = N, count = 0;
	for (int i = 0; temp > 0; i++) {	
		count++;
		temp /= 10;

	}
	int* arr = new int[count];
	temp = N;

	for (int i = 0; temp > 0; i++) {
		arr[i] = temp % 10;
		temp /= 10;
	}

	cout << "The number of values is: " << count << endl;
	if (i <= count)
		cout << "The value is: " << arr[count - i];
	else
		cout << "This value isn't exist" << endl;
	
	delete[] arr;

	return 0;
}