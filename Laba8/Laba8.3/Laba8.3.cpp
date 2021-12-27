//Задание 3. Вариант3. Ведомость абитуриентов, сдавших вступительные экзамены в
//университет, содержит: Ф.И.О.абитуриента, оценки.Определить средний балл
//по университету и вывести список абитуриентов, средний балл которых
//выше среднего балла по университету.Первыми в списке должны идти
//студенты, сдавшие все экзамены на 100.
#include <iostream>
#include <fstream>
#include <filesystem>
#include <conio.h>

class Abiturients {
private:
	std::string surname;
	std::string name;
	std::string patronymic;
	int physics;
	int math;
	int language;
public:
	friend Abiturients* Delete(Abiturients*& Obj, int& amount, std::ifstream& inf);
	friend int SumByte(Abiturients* Obj, int pos);
	friend Abiturients* AddAbitura(Abiturients*& Obj, int& amount, std::ifstream& inf);
	friend Abiturients* EditAbitura(Abiturients*& Obj, int& amount, std::ifstream& inf);
	friend void Input_bool(bool& N);
	friend void Input_string(std::string& s);
	friend void Input_int(int& N);
	double Score() {
		return (math + language + physics) / 3;
	}
	std::string GetSurname() {
		return surname;
	}
	std::string GetName() {
		return name;
	}
	std::string GetPatron() {
		return patronymic;
	}
	void SetSurname() {
		std::cin >> surname;
	}
	void SetName() {
		std::cin >> name;
	}
	void SetPatron() {
		 std::cin >> patronymic;
	}
	int GetPhys() {
		return physics;
	}
	int GetMath() {
		return math;
	}
	int GetLang() {
		return language;
	}
	void SetPhys() {
		std::cin >> physics;
	}
	void SetMath() {
		 std::cin >> math;
	}
	void SetLang() {
		std::cin >> language;
	}
	void GetData(std::ifstream& inf) {
		inf >> Abiturients::surname >> Abiturients::name >> Abiturients::patronymic >> 
			Abiturients::physics >> Abiturients::math >> Abiturients::language;
	}
};

//int abitura = 10;

void ShakeSort(Abiturients* Obj, const int amount);
void ShowAverageUni(Abiturients* Obj, const int amount);
void ShowAbitur(Abiturients* Obj, const int amount);
int Digits(int n);


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

void Input_int(int& N) {
	while (true) {
		std::cin >> N;
		if ((std::cin.get() != '\n')) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid. Try again" << std::endl;
		}
		else {
			break;
		}
	}
}

void Input_bool(bool& N) {
	while (true) {
		std::cin >> N;
		if ((std::cin.get() != '\n')) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "That input is invalid. Try again" << std::endl;
		}
		else {
			break;
		}
	}
}

int main()
{
	int editor;
	int amountAbiturients;
	std::ifstream inf("Data.txt");
	// Если мы не можем открыть этот файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующее сообщение об ошибке и выполняем функцию exit()
		std::cerr << "Uh oh, Data.txt could not be opened for reading!" << std::endl;
		return 0;
	}
	while (true) {
		std::ifstream inf("Data.txt");
		std::cout << "Number of abiturients: ";
		Input_int(amountAbiturients);
		Abiturients* OurAbiturients = new Abiturients[amountAbiturients];
		for (int i = 0; i < amountAbiturients; ++i) {
			OurAbiturients[i].GetData(inf);
		}
		std::cout << "Do you want to add new elements in this array? (1 - yes, 0 - no)";
		Input_int(editor);
		if (editor) {
			OurAbiturients = AddAbitura(OurAbiturients, amountAbiturients, inf);
		}
		std::cout << std::endl;
		std::cout << "Do you want to edit elements in your array? (1 - yes, 0 - no)";
		Input_int(editor);
		if (editor) {
			OurAbiturients = EditAbitura(OurAbiturients, amountAbiturients, inf);
		}
		std::cout << std::endl;
		std::cout << "Do you want to delete elements in your array? (1 - yes, 0 - no)";
		Input_int(editor);
		if (editor) {
			OurAbiturients = Delete(OurAbiturients, amountAbiturients, inf);
		}
		std::cout << std::endl;
		ShakeSort(OurAbiturients, amountAbiturients);
		ShowAverageUni(OurAbiturients, amountAbiturients);
		std::cout << "Do you want to exit from the program? (1 - yes, 0 - no)";
		std::cin >> editor;
		if (editor)
			break;
		system("cls");
	}

	return 0;
}


void ShakeSort(Abiturients* Obj, const int amount) {
	int left = 0, right = amount - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (Obj[i].Score() < Obj[i + 1].Score()) // если следующий элемент меньше текущего,
			{             // меняем их местами
				Abiturients t = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (Obj[i - 1].Score() < Obj[i].Score()) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				Abiturients t = Obj[i];
				Obj[i] = Obj[i - 1];
				Obj[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}

void ShowAverageUni(Abiturients* Obj, const int amount) {
	system("cls");
	std::cout << "\t\t ALL ABITURIENTS" << std::endl;
	std::cout << "N " << "Surname\t" << "Name\t" << "Patronymic\t" << "Physics\t" << "Math\t" << "Language\t" << "Average Score\t" << std::endl;
	std::cout << "========================================" << std::endl;
	for (int i = 0; i < amount; ++i) {
		std::cout << i + 1 << " " << Obj[i].GetSurname() << '\t' << Obj[i].GetName() << '\t' << Obj[i].GetPatron() << '\t'
			<< Obj[i].GetPhys() << '\t' << Obj[i].GetMath() << '\t' << Obj[i].GetLang() << '\t' << Obj[i].Score() << std::endl;
	}
	double UniScore = 0;
	for (int i = 0; i < amount; ++i) {
		UniScore += Obj[i].Score();
	}
	UniScore /= amount;
	std::cout << std::endl << std::endl;
	std::cout << "\t ABITURIENTS WITH AVERAGE SCORE MORE THAN AVERAGE SCORE IN THE UNI" << std::endl;
	std::cout << "N " << "Surname\t" << "Name\t" << "Patronymic\t" << "Physics\t" << "Math\t" << "Language\t" << "Average Score\t" << std::endl;
	std::cout << "========================================" << std::endl;
	for (int i = 0; i < amount; ++i) {
		if (Obj[i].Score() >= UniScore) {
			std::cout << i + 1 << " " << Obj[i].GetSurname() << '\t' << Obj[i].GetName() << '\t' << Obj[i].GetPatron() << '\t'
				<< Obj[i].GetPhys() << '\t' << Obj[i].GetMath() << '\t' << Obj[i].GetLang() << '\t' << Obj[i].Score() << std::endl;
		}
	}
}

int Digits(int n) {
	int counter = 0;
	while (n) {
		n /= 10;
		++counter;
	}
	return counter;
}

int SumByte(Abiturients* Obj, int pos) {
	int size = 0;
	for (int i = 0; i < pos; ++i) {
		size += Obj[i].surname.size();
		size += Obj[i].name.size();
		size += Obj[i].patronymic.size();
		size += Digits(Obj[i].physics);
		size += Digits(Obj[i].math);
		size += Digits(Obj[i].language);
		size += 6; // Ну у нас 5 пробелов и \n
	}
	return size;
}

Abiturients* AddAbitura(Abiturients*& Obj, int& amount, std::ifstream& inf) {
	std::ofstream fout;
	fout.open("Data.txt", std::ios::in | std::ios::out | std::ios::binary);
	fout.seekp(0, std::ios_base::end);
	int count;
	std::cout << "Enter a number of added elements: ";
	Input_int(count);
	while (count <= 0) {
		std::cout << "We can't edit an array";
		Input_int(count);
	}
	Abiturients* New_Obj = new Abiturients[amount + count];
	for (int i = 0; i < amount; ++i) {
		New_Obj[i] = Obj[i];
	}
	delete[] Obj;
	for (int i = amount; i < amount + count; ++i) {
		std::cout << "Enter a surname of new abiturient: ";
		std::cin >> New_Obj[i].surname;
		fout << New_Obj[i].surname << ' ';
		std::cout << "Enter a name of new abiturient: ";
		std::cin >> New_Obj[i].name;
		fout << New_Obj[i].name << ' ';
		std::cout << "Enter a patronymic of new abiturient: ";
		std::cin >> New_Obj[i].patronymic;
		fout << New_Obj[i].patronymic << ' ';
		std::cout << "Enter a physics of new abiturient: ";
		std::cin >> New_Obj[i].physics;
		fout << New_Obj[i].physics << ' ';
		std::cout << "Enter a math of new abiturient: ";
		std::cin >> New_Obj[i].math;
		fout << New_Obj[i].math << ' ';
		std::cout << "Enter a language of new abiturient: ";
		std::cin >> New_Obj[i].language;
		fout << New_Obj[i].language << '\n';
	}
	amount += count;
	fout.close();
	return New_Obj;
}

Abiturients* EditAbitura(Abiturients*& Obj, int& amount, std::ifstream& inf) {
	std::ofstream fout;
	fout.open("Data.txt", std::ios::in | std::ios::out | std::ios::binary);
	int count;
	std::cout << "Enter a number of element, which we want to edit: ";
	Input_int(count);
	Abiturients* New_Obj = new Abiturients[amount];
	bool temp = true;
	for (int i = 0, j = 0; j < amount; ++i, ++j) {
		if (temp && i + 1 == count) {
			temp = false;
			continue;
		}
		New_Obj[i] = Obj[j];
	}
	int size = SumByte(Obj, count - 1);
	std::cout << "Enter a new surname(Enter 0, if you want to save previous value, else enter 1): ";
	Input_bool(temp);
	if (temp)
		Input_string(New_Obj[count - 1].surname);
	else
		New_Obj[count - 1].surname = Obj[count - 1].surname;

	std::cout << "Enter a new name(Enter 0, if you want to save previous value, else enter 1): ";
	Input_bool(temp);	
	if (temp)
		Input_string(New_Obj[count - 1].name);
	else
		New_Obj[count - 1].name = Obj[count - 1].name;

	std::cout << "Enter a new patronymic(Enter 0, if you want to save previous value, else enter 1): ";
	Input_bool(temp);
	if (temp)
		Input_string(New_Obj[count - 1].patronymic);
	else
		New_Obj[count - 1].patronymic = Obj[count - 1].patronymic;

	std::cout << "Enter a new physic(Enter 0, if you want to save previous value, else enter 1): ";
	Input_bool(temp);
	if (temp)
		Input_int(New_Obj[count - 1].physics);
	else
		New_Obj[count - 1].physics = Obj[count - 1].physics;
	std::cout << "Enter a new math(Enter 0, if you want to save previous value, else enter 1): ";
	Input_bool(temp);
	if (temp)
		Input_int(New_Obj[count - 1].math);
	else
		New_Obj[count - 1].math = Obj[count - 1].math;

	std::cout << "Enter a new language(Enter 0, if you want to save previous value, else enter 1): ";
	Input_bool(temp);
	if (temp)
		Input_int(New_Obj[count - 1].language);
	else
		New_Obj[count - 1].language = Obj[count - 1].language;

	std::filesystem::resize_file("Data.txt", size);
	for (int i = count - 1; i < amount; ++i) {
		fout << New_Obj[i].surname << ' ';
		fout << New_Obj[i].name << ' ';
		fout << New_Obj[i].patronymic << ' ';
		fout << New_Obj[i].physics << ' ';
		fout << New_Obj[i].math << ' ';
		fout << New_Obj[i].language << '\n';
	}
	delete[] Obj;
	return New_Obj;
}

Abiturients* Delete(Abiturients*& Obj, int& amount, std::ifstream& inf) {
	int count;
	std::cout << "Enter a position: ";
	Input_int(count);
	while (count > amount || !count) {
		std::cout << "We can't edit an array!";
		Input_int(count);
	}
	bool temp = true;
	Abiturients* New_Obj = new Abiturients[amount - 1];
	for (int i = 0, j = 0; j < amount; ++i, ++j) {
		if (temp && i + 1 == count) {
			temp = false;
			--i;
			continue;
		}
		New_Obj[i] = Obj[j];
	}
	delete[] Obj;
	std::ofstream fout;
	fout.open("Data.txt", std::ios::in | std::ios::out | std::ios::binary);
	int size = SumByte(New_Obj, count - 1);
	fout.seekp(size, std::ios_base::beg);

	std::filesystem::resize_file("Data.txt", size);
	for (int i = count - 1; i < amount - 1; ++i) {
		fout << New_Obj[i].surname << ' ';
		fout << New_Obj[i].name << ' ';
		fout << New_Obj[i].patronymic << ' ';
		fout << New_Obj[i].physics << ' ';
		fout << New_Obj[i].math << ' ';
		fout << New_Obj[i].language << '\n';
	}
	fout.close();
	--amount;
	return New_Obj;
}