//Задачка 12. Выполнил Коновалюк М.А.
#include <iostream>

void New_array(int *old_arr, int N);
void Input(int& N);

int main() {
	int N;
	Input(N);
	int *old_arr = new int[N];
	for (int i = 0; i < N; i++) {
		Input(old_arr[i]);
	}
	New_array(old_arr, N);

	delete[] old_arr;

	return 0;
}

void Input(int& N) {
	while (true) {
		std::cout << "Enter a num of values: " << std::endl;
		std::cin >> N;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid. Try again" << std::endl;
		}
		else {
			std::cin.ignore(32767, '\n');
			break;
		}
	}
}

void New_array(int *old_arr, int N)
{
	int count = 0, length = N, k = 0;
	int* new_arr = new int[length];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (old_arr[j] == old_arr[i])
				count++;
		}
		if (count == 0) {
			new_arr[k] = old_arr[i];
			k++;
		}
		else
			length--;
		count = 0;
	}
	std::cout << "New array: ";
	for (int i = 0; i < length; i++) {
		std::cout << new_arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Length of the new array: " << length;

	delete[] new_arr;
}
