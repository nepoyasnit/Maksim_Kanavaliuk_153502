//TASK 1
//Дана строка символов, состоящая из цифр, разделенных пробелами.Вывести
//четные числа этой строки.
// Выполнил Коновалюк М.А.
#include <iostream>

int main()
{
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

    for (int i = 0; i < length; i++) {
        // Этот кусок кода - функция для тестов
        if ((int)(str[i] - 48) % 2 == 0 && str[i] != ' ' && (int)(str[i] - 48) != 0) {
            std::cout << str[i] << " ";
        }
        //
    }

    free(str);
    
    return 0;
}

