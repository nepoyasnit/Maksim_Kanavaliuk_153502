//Задача 6
//Анаграммой слова называется любая перестановка всех букв слова.
//Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
//OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
//SOOL.
//Напишите программу, которая выводит количество различных
//анаграмм, которые могут получиться из этого слова.
//Выполнил Коновалюк М.А.

#include <iostream>

long double factorial(int n) {
    long double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void Solve() {
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

    long double answ = factorial(length);

    long double max = 0, counter = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (str[i] == str[j]) {
                ++counter;
            }
        }
        answ /= counter;
        counter = 0;
    }

    std::cout << "Result: " << answ;
    free(str);
}

int main()
{
    Solve();

	return 0;
}
