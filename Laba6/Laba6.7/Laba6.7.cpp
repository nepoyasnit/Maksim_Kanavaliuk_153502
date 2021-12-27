//Задача 7
//В заданной строке S найти максимальную по длине подстроку, которая
//не является палиндромом.
//Формат входных данных :
//На вход задается строка S, состоящая из строчных букв латинского
//алфавита(1 ⩽ | S | ⩽ 105).
//Формат выходных данных :
//Выведите одно целое число — длина максимального непалиндрома.
//Если такой подстроки не существует, то выведите - 1.
//Коновалюк М.А.

#include <iostream>

int Solve() {
    int maxN = 2;
    char* str = (char*)malloc(maxN * sizeof(char));
    int length;
    for (length = 0; '\n' - (str[length] = getchar()); ++length) {
        if (length == maxN - 1) {
            str = (char*)realloc(str, (maxN *= 2) * sizeof(char));
        }
    }
    str = (char*)realloc(str, (length + 1) * sizeof(char));
    str[length] = '\0';

    //Проверка на одинаковость символов

    bool temp = true;
    for (int i = 1; i < length; i++) {
        if (str[i] != str[0]) {
            temp = false;
            break;
        }
    }
    if (temp) {
        std::cout << "-1";
        free(str);
        return 0;
    }
    int j = 0;

    // Проверка на палиндром 

    temp = true;
    for (int i = length - 1; i >= 0; i--) {
        for (j = 0; j <= i / 2; j++) {
            if (str[j] != str[i - j]) {
                temp = false;
                break;
            }
        }
        if (!temp) {
            std::cout << "Result: " << i + 1 << std::endl;
            free(str);
            return 0;
        }
    }
    std::cout << "-1";
    free(str);
    return 0;
}

int main()
{
	Solve();

	return 0;
}