//Задание 2. Вариант 10, Информация об участниках спортивных соревнований
//содержит : наименование страны, название команды, Ф.И.О.игрока, игровой
//номер, возраст, рост, вес.Вывести информацию о самой молодой команде.
#include <iostream>
#include <fstream>
#include <string>

struct Sportsmens {
	std::string country;
	std::string team;
	std::string surname;
	std::string name;
	std::string patronymic;
	int GameN;
	int age;
	int height;
	int weight;
};

void SetData(Sportsmens* Obj, const int amount);
void ShowData(Sportsmens* Obj, const int amount);
void ShakeSort(Sportsmens* Obj, const int amount);
int sports = 8;

void Input_int(int& N) {
	while (true) {
		std::cin >> N;
		if ((std::cin.get() != '\n')|| N > sports) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid. Try again" << std::endl;
		}
		else {
			break;
		}
	}
}


int main() {
	int amountSportsmens;
	std::ifstream inf("Data.txt");
	std::cout << "Number of sportsmens: ";
	Input_int(amountSportsmens);
	Sportsmens* OurSportsmens = new Sportsmens[amountSportsmens];
	SetData(OurSportsmens, amountSportsmens);
	ShakeSort(OurSportsmens, amountSportsmens);
	std::cout << "========================================" << std::endl;
	ShowData(OurSportsmens, amountSportsmens);

	return 0;
}

void SetData(Sportsmens* Obj, const int amount) {
	std::ifstream inf("Data.txt");

	// Если мы не можем открыть этот файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующее сообщение об ошибке и выполняем функцию exit()
		std::cerr << "Uh oh, Data.txt could not be opened for reading!" << std::endl;
		exit(1);
	}

	// Пока есть данные, которые мы можем прочитать,
	for (int i = 0; inf && i < amount; ++i) {
		inf >> Obj[i].country >> Obj[i].team >> Obj[i].surname >> Obj[i].name >> Obj[i].patronymic >> Obj[i].GameN >> Obj[i].age >> Obj[i].height >> Obj[i].weight;
	}
}

void ShakeSort(Sportsmens* Obj, const int amount) {
	int left = 0, right = amount - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (Obj[i].age > Obj[i + 1].age) // если следующий элемент меньше текущего,
			{             // меняем их местами
				Sportsmens t = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (Obj[i - 1].age > Obj[i].age) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				Sportsmens t = Obj[i];
				Obj[i] = Obj[i - 1];
				Obj[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}

void ShowData(Sportsmens* Obj, const int amount) {
	system("cls");
	std::ofstream outf("Out.txt");
	for (int i = 0; i < amount; ++i) {
		std::cout << Obj[i].country << '\t' << Obj[i].team << '\t' << Obj[i].surname << ' ' << Obj[i].name << ' ' << Obj[i].patronymic << '\t' << Obj[i].GameN << '\t' << Obj[i].age << '\t' << Obj[i].height << '\t' << Obj[i].weight << std::endl;
	}
	std::string min_team = "";
	double min_sum = 1e9;
	for (int i = 0; i < amount; ++i) {
		double sum = 0;
		int counter = 0;
		for (int j = i; j < amount; ++j) {
			if (Obj[j].team == Obj[i].team) {
				sum += Obj[i].age;
				++counter;
			}
		}
		sum /= counter;
		if (sum < min_sum) {
			min_team = Obj[i].team;
			min_sum = sum;
		}
	}
	std::cout << "========================================" << std::endl;

	for (int i = 0; i < amount; ++i) {
		if (Obj[i].team == min_team) {
			outf << Obj[i].country << '\t' << Obj[i].team << '\t' << Obj[i].surname << ' ' << Obj[i].name << ' ' << Obj[i].patronymic << '\t' << Obj[i].GameN << '\t' << Obj[i].age << '\t' << Obj[i].height << '\t' << Obj[i].weight << std::endl;
		}
	}
}
