//Задачка 14. Выполнил Коновалюк М.А.
#include <iostream>

void Input_int(int& N);

int main() {
	int N, M;
	Input_int(N);
	Input_int(M);
	char** A = 0;
	A = (char**)malloc(N * 4);

	for (int i = 0; i < N; i++) {
		A[i] = (char*)malloc(M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> A[i][j];
		}
	}
	int bombs = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '.') {
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
				if (left) {
					if (A[i][j - 1] == '*')
						bombs++;
				}
				if (right) {
					if (A[i][j + 1] == '*')
						bombs++;
				}
				if (up) {
					if (A[i - 1][j] == '*')
						bombs++;
					if (left) {
						if (A[i - 1][j - 1] == '*')
							bombs++;
					}
					if (right) {
						if (A[i - 1][j + 1] == '*')
							bombs++;
					}
				}
				if (down) {
					if (A[i + 1][j] == '*')
						bombs++;
					if (left) {
						if (A[i + 1][j - 1] == '*')
							bombs++;
					}
					if (right) {
						if (A[i + 1][j + 1] == '*')
							bombs++;
					}
				}
				A[i][j] = bombs + 48;
			}
			bombs = 0;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			std::cout << A[i][j];
		std::cout << std::endl;
	}

	for (int i = 0; i < M; i++) {
		free(A[i]);
	}
	free(A);

	return 0;
}

void Input_int(int& N) {
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
