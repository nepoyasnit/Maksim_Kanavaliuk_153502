//Задание 4. Осуществить сложение и вычитание чисел в заданной системе
//счисления.В другую систему счисления не переводить.В системах
//счисления больших десятичной использовать буквы по аналогии с
//шестнадцатеричной системой.Разработать функции для выполнения
//операции сложения и функции для выполнения операции вычитания.
//Предусмотреть ввод положительных и отрицательных чисел.
//Выполнил Коновалюк М.А.
#include <iostream>
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"

my_str sum(my_str str1, my_str str2) {
    my_str code17 = "0123456789ABCDEFG";
    str1.reverse();
    str2.reverse();
    while (str1.size() < str2.size()) {
        str1 += '0';
    }
    while (str2.size() < str1.size()) {
        str2 += '0';
    }
    my_str result;
    int l = str1.size();
    int d = 0;
    for (int i = 0; i < l; ++i) {
        int num1 = code17.find_i(str1[i]);
        int num2 = code17.find_i(str2[i]);
        result += code17[(num1 + num2 + d) % 16];
        d = (num1 + num2 + d) / 16;
    }
    result.reverse();
    return result;
}
my_str sub(my_str str1, my_str str2) {
    my_str code17 = "0123456789ABCDEFG";
    str1.reverse();
    str2.reverse();
    my_str s = str1;
    while (str1.size() < str2.size()) {
        str1 += '0';
    }
    while (str2.size() < str1.size()) {
        str2 += '0';
    }
    my_str result;
    int l = str1.size();
    int d = 0;
    for (int i = 0; i < l; ++i) {
        int num1 = code17.find_i(str1[i]);
        int num2 = code17.find_i(str2[i]);
        result += code17[(num1 - num2 + d + 16) % 16];
        d = (num1 - num2 + d - 16) / 16;
    }
    result.reverse();
    return result;
}
int main() {
    std::cout << "Enter two numbers: " << std::endl;
    my_str s1, s2;
    std::cin >> s1 >> s2;
    std::cout << "Sum is " << sum(s1, s2) << std::endl;
    std::cout << "Substraction is " << sub(s1, s2);
    return 0;
}
