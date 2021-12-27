//Задача 2
//10. В тексте найти и вывести на экран все слова максимальной и минимальной
//длины.
//Выполнил Коновалюк М.А.
#include <iostream>

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
    int maxLength = 0, counter = 0, minLength = 1e9;

    for (int i = 0; i < length; i++) {
        if (str[i] != ' ')
            ++counter;
        else {
            if (counter > maxLength)
                maxLength = counter;
            if (counter > 0 && counter < minLength)
                minLength = counter;
            counter = 0;
        }
    }
    if (counter > maxLength)
        maxLength = counter;
    if (counter > 0 && counter < minLength)
        minLength = counter;

    std::cout << "MIN: " << minLength << std::endl;
    std::cout << "MAX: " << maxLength << std::endl;

    int temp = 0, start = 0;

    std::cout << std::endl;
    std::cout << "Maximal: ";

    for (int i = 0; i < length; i++) {
        if (!start || str[i - 1] == ' ') {
            temp = 0;
            for (int j = i; str[j] != ' ' && str[j] != '\0'; j++) {
                ++temp;
            }
        }
        if (temp == maxLength) {
            std::cout << str[i];
        }
        ++start;
    }
    start = 0;

    std::cout << std::endl;
    std::cout << "Minimal: ";

    for (int i = 0; i < length; i++) {
        if (!start || str[i - 1] == ' ') {
            temp = 0;
            for (int j = i; str[j] != ' ' && str[j] != '\0'; j++) {
                ++temp;
            }
        }
        if (temp == minLength) {
            std::cout << str[i];
        }
        ++start;
    }

    free(str);
}

int main()
{
	Solve();

	return 0;
}
