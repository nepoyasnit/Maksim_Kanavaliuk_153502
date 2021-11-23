//Задачка 15. Выполнил Коновалюк М.А.
#include <iostream> 

void Input_int(int& N);

int main() {
	int N;
	Input_int(N);
	int counter = 0;
	int l = 1;

	while (N > l) {
		counter++;
		l += counter * 2;
	}

	if (N < l - counter) {
		l -= counter * 2;
		counter--;
		std::cout << "Line: " << counter + 1<< std::endl;
		std::cout << "Column: " << l + counter - N + 1;
	}
	else if (N >= l - counter && N <= l) {
		std::cout << "Line: " << N - (l - counter) + 1 << std::endl;
		std::cout << "Column: " << counter + 1;
	}

	return 0;
}

void Input_int(int& N) {
	while (true) {
		std::cout << "Enter a num: " << std::endl;
		std::cin >> N;
		if (std::cin.get() != '\n') {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid. Try again" << std::endl;
		}
		else {
			break;
		}
	}
}