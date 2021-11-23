//Задачка 13. Выполнил Коновалюк М.А.
#include <iostream>

void Input(int& N);

int main() {
	int N;
	Input(N);
	int sum = 0;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		if (i == N - 1)
			sum += arr[i];
		else
			sum += arr[i] - 1;
	}

	std::cout << "The num of power sockets is " << sum << std::endl;

	return 0;
}

void Input(int& N) {
	while (true) {
		std::cout << "Enter a num: " << std::endl;
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