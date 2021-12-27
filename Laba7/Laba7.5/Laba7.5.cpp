//Задание 5. Перевести число из арабской системы записи чисел в римскую.
//Выполнил Коновалюк М.А.
#include <iostream>
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"

void Input_int(int& N) {
    while (true) {
        std::cout << "Enter a num: " << std::endl;
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

my_str RimConverter(int x) {
    my_str y;
    switch (x) {
    case 1:
        y = "I";
        break;
    case 5:
        y = "V";
        break;
    case 10:
        y = "X";
        break;
    case 50:
        y = "L";
        break;
    case 100:
        y = "C";
        break;
    case 500:
        y = "D";
        break;
    case 1000:
        y = "M";
        break;
    default:
        y = "err";
        break;
    }
    return y;
}

my_str Convert(int ar_num) {
    my_str temp = "";
    int counter = 0;

    if (((ar_num < 0) || (ar_num > 3999))) { //4000 - знаки, которых нет на клаве 
        return "Invalid input! Please, try again!";
    }
    else {
        while (ar_num > 0) {
            if ((ar_num >= 1) && (ar_num <= 9))
                counter = 1;
            else if ((ar_num >= 10) && (ar_num <= 99))
                counter = 10;
            else if ((ar_num >= 100) && (ar_num <= 999))
                counter = 100;
            else if ((ar_num >= 1000) && (ar_num <= 3999))
                counter = 1000;
            if (ar_num >= 9 * counter) {
                temp = temp + RimConverter(counter) + RimConverter(counter * 10);
                ar_num = ar_num - 9 * counter;
            }
            else if (ar_num >= 5 * counter) {
                temp = temp + RimConverter(5 * counter);
                ar_num = ar_num - 5 * counter;
            }
            else if (ar_num >= 4 * counter) {
                temp = temp + RimConverter(counter) + RimConverter(5 * counter);
                ar_num = ar_num - 4 * counter;
            }
            while (ar_num >= counter) {
                temp = temp + RimConverter(counter);
                ar_num = ar_num - counter;
            }
        }
    }
    return temp;
}

int main() {
    int ar_num;
    Input_int(ar_num);
    my_str result = Convert(ar_num);
    std::cout << result;

    return 0;
}
