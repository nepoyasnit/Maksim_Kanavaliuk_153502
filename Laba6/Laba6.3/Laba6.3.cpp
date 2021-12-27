//Задача 3
//10.Ввести массив строк.В функции для каждой строки
//проверить, является она палиндромом(симметричной с точностью до
//    пробелов) или нет.Например, палиндромами являются цепочки :
//«АРГЕНТИНА МАНИТ НЕ ГРА» и «А РОЗА УПАЛА НА ЛАПУ АЗОРА».
//Результат вывести на экран.Стандартных функций работы со
//строками не использовать.
//Выполнил Коновалюк М.А.

#include <iostream>

bool Palindrom(char* s, int l) {
	for (int i = 0, j = l - 1; i < j; ++i, --j) {
        while (s[i] == ' ')
            ++i;
        while (s[j] == ' ')
            --j;
        if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

void Solve(){
    int size = 2;
    int last_elem = 1;
    int last_str;
    int n = 1000, k = 1000;

    char** str = (char**)malloc(k * sizeof(char*));
    for (int i = 0; i < k; i++) {
        str[i] = (char*)malloc(n * sizeof(char));
    }

    char* length_str = (char*)malloc(k * sizeof(char));

    for (int length1 = 0; length1 < k; length1++) {
        for (int length = 0; '\n' - (str[length1][length] = getchar()); ++length) {
            last_elem = length;
        }
        if (str[length1][0] == '\n') {
            break;
        }
        str[length1][last_elem + 1] = '\0';
        length_str[length1] = last_elem + 1;
        last_str = length1 + 1;
    }

    str = (char**)realloc(str, last_str * sizeof(char*));
    length_str = (char*)realloc(length_str, last_str * sizeof(char));

    for (int i = 0; i < last_str; i++) {
        if (Palindrom(str[i], length_str[i])) {
            std::cout << "TRUE" << std::endl;
        }
        else {
            std::cout << "FALSE" << std::endl;
        }
    }

    for (int i = 0; i < last_str; i++) {
        free(str[i]);
    }
    free(str);
}

int main()
{
	Solve();

	return 0;
}
