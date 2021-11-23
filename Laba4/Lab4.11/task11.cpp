//Задачка 11. Выполнил Коновалюк М.А.
#include <iostream>
#include <ctime>
using namespace std;

void Input(int& N);

int main() {
	srand(1);
	int N;
	Input(N);
	//cin >> N;
	int*** d_arr;
	
	d_arr = new int** [N];
	for (int i = 0; i < N; i++) {
		d_arr[i] = new int* [N];
		for (int j = 0; j < N; j++) {
			d_arr[i][j] = new int[N];
		}
	} 

	//i - z; l,j - x,y
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int l = 0; l < N; l++) {
				//Input(d_arr[i][j][l]);
				/*while (true) {
					cout << "Enter a num: " << endl;
					cin >> d_arr[i][j][l];
					if (cin.fail()) {
						cin.clear();
						cin.ignore(32767, '\n');
						cout << "That input is invalid. Try again" << endl;
					}
					else {
						cin.ignore(32767, '\n');
						break;
					}
				}*/
				d_arr[i][j][l] = rand() % 3 + 1;
			}
		}
	}
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (int i = 0; i < N; i++) {
		sum1 += d_arr[i][i][i];
		sum2 += d_arr[i][N - i - 1][N - i - 1];
		sum3 += d_arr[i][N - 1 - i][i];
		sum4 += d_arr[i][i][N - 1 - i];
	}

	cout << "All sums: " << sum1 << " : " << sum2 << " : " << sum3 << " : " << sum4 << endl;

	if (sum1 > sum2 && sum1 > sum3 && sum1 > sum4)
		cout << "1";
	else if (sum2 > sum1 && sum2 > sum3 && sum2 > sum4)
		cout << "2";
	else if (sum3 > sum1 && sum3 > sum2 && sum3 > sum4)
		cout << "3";
	else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3)
		cout << "4";
	else
		cout << "All diagonals are equal!" << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			delete[] d_arr[i][j];
	}
	for (int i = 0; i < N; i++)
		delete[] d_arr[i];
	delete[] d_arr;

	return 0;
}

void Input(int& N) {
	while (true) {
		cout << "Enter a num: " << endl;
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
}
