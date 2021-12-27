//Задача 9.
//Сумма чисел в строке
//В заданной строке, состоящей из букв, цифр и прочих символов, найдите
//сумму всех чисел
//Выполнил Коновалюк М.А.

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

    double sum_d = 0;
    int sum_i = 0;
    int sign = 1;

    for (int i = 0; i < length; i++) {
        if (str[i] == '-') {
            sign = -1;
        }
        int last_sum = 0;
        if ((int)str[i] >= 48 && (int)str[i] <= 57) {
            //sum_i += (int)str[i] - 48;
            int j = 0;
            int temp = 1;
            int counter = i;
            int temp_sum = 0;
            while ((int)str[counter] >= 48 && (int)str[counter] <= 57) {
                last_sum += ((int)str[counter] - 48) * temp;
                sum_i += ((int)str[counter] - 48) * temp;
                temp *= 10;
                ++counter;
                ++j;
            }
            i += j;
        }
        if (str[i] == '.') {
            int counter = i - 1;
            int temp = 1;
            double left = 0, right = 0;
            sum_i -= last_sum;
            // ПРОВЕРКА ЧИСЕЛ СЛЕВА ОТ ТОЧКИ
            while ((int)str[counter] >= 48 && (int)str[counter] <= 57) {
                left += ((double)str[counter] - 48)*temp;
                //sum_i -= left / temp;
                temp *= 10;

                --counter;
            }
            /*int z = 1;
            if (str[counter] = '-') {
                z = -1;
            }*/
            temp = 10;
            counter = i + 1;
            int j = 0;
            // ПРОВЕРКА ЧИСЕЛ СПРАВА ОТ ТОЧКИ
            while ((int)str[counter] >= 48 && (int)str[counter] <= 57) {
                right += ((double)str[counter] - 48) / temp;
                //sum_i -= (right * temp) / last_eq;
                //last_eq = temp;
                temp *= 10;
                ++counter;
                ++j;
            }
            i += j;
            //right /= temp;
            sum_d += sign*(right + left);
        }
    }

    std::cout << "Result: " << (double)sum_i + sum_d;

    free(str);

	return 0;
}
