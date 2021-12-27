//Задание 1. Вариант 10. Информация о сотрудниках содержит ФИО, номер отдела, должность,
//стаж работы на предприятии.Вывести список сотрудников заданного отдела,
//имеющих стаж работы на предприятии более 20 лет(Шейкер сортировка по
//возрастанию).
#include <iostream>
#include <string>
#include <fstream>

struct Workers {
	std::string surname;
	std::string name;
	std::string patronymic;
	int departmentN;
	std::string post;
	int experience;
};

Workers* AddStruct(Workers* Obj, const int amount);
void ShakeSort(Workers* Obj, const int amount);
void SetData(Workers* Obj, const int amount/*, std::ifstream& inf*/);
void ShowData(Workers* Obj, const int amount);

void Input_int(int& N) {
	while (true) {
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

void Input_string(std::string& s) {
	while (true) {
		bool isTrue = true;
		std::cin >> s;
		for (int i = 0; i < s.size(); ++i) {
			if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "That input is invalid. Try again" << std::endl;
				isTrue = false;
				break;
			}
		}
		if (isTrue)
			return;
	}
}

int main()
{
	Workers* OurWorkers = 0;
	int workersN = 0;
	int YesOrNo = 0;
	/*std::ifstream inf("Workers.txt");
	int counter = 6;*/
	do {
		OurWorkers = AddStruct(OurWorkers, workersN);
		SetData(OurWorkers, workersN/*, inf*/);

		++workersN;
		std::cout << "Continue the input?(1 - yes, 0 - no)";
		Input_int(YesOrNo);
		//--counter;
	} while (YesOrNo/*counter*/);

	ShakeSort(OurWorkers, workersN);
	ShowData(OurWorkers, workersN);

	delete[] OurWorkers;

	return 0;
}

Workers* AddStruct(Workers* Obj, const int amount) {
	if (amount == 0) {
		Obj = new Workers[amount + 1];
	}
	else {
		Workers* tempObj = new Workers[amount + 1];
		for (int i = 0; i < amount; ++i) {
			tempObj[i] = Obj[i];
		}
		delete[] Obj;
		Obj = tempObj;
	}
	return Obj;
}

void SetData(Workers* Obj, const int amount/*, std::ifstream& inf*/) {
	std::cout << "Enter a new information: " << std::endl;
	std::cout << "Surname: ";
	Input_string(Obj[amount].surname);
	std::cout << "Name: ";
	Input_string(Obj[amount].name);
	std::cout << "Patronymic: ";
	Input_string(Obj[amount].patronymic);
	std::cout << "Number of the department: ";
	Input_int(Obj[amount].departmentN);
	std::cout << "Experience: ";
	Input_int(Obj[amount].experience);
	std::cout << "Post: ";
	Input_string(Obj[amount].post);
	std::cin.get();
	std::cout << std::endl;
}

void ShakeSort(Workers* Obj, const int amount) {
	int left = 0, right = amount - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (Obj[i].experience > Obj[i + 1].experience) // если следующий элемент меньше текущего,
			{             // меняем их местами
				Workers t = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (Obj[i - 1].experience > Obj[i].experience) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				Workers t = Obj[i];
				Obj[i] = Obj[i - 1];
				Obj[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}

void ShowData(Workers* Obj, const int amount) {
	int department;
	system("cls");
	std::cout << "Enter a department: ";
	Input_int(department);
	system("cls");
	std::cout << "\t\tALL WORKERS";
	std::cout << "N " << "Surname\t" << "Name\t" << "Patronymic\t" << "Department N\t" << "Post\t" << "Experience\t" << std::endl;
	std::cout << "========================================" << std::endl;
	for (int i = 0; i < amount; ++i) {
			std::cout << i + 1 << " " << Obj[i].surname << '\t' << Obj[i].name << '\t' << Obj[i].patronymic << '\t' << Obj[i].departmentN << '\t' << Obj[i].post << '\t' << Obj[i].experience << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl << "\t\tWITH SORTING" << std::endl << std::endl;
	std::cout << "N " << "Surname\t" << "Name\t" << "Patronymic\t" << "Department N\t" << "Post\t" << "Experience\t" << std::endl;
	std::cout << "========================================" << std::endl;
	for (int i = 0; i < amount; ++i) {
		if(Obj[i].departmentN == department && Obj[i].experience > 20)
		std::cout << i + 1 << " " << Obj[i].surname << '\t' << Obj[i].name << '\t' << Obj[i].patronymic << '\t' << Obj[i].departmentN << '\t' << Obj[i].post << '\t' << Obj[i].experience << std::endl;
	}
}