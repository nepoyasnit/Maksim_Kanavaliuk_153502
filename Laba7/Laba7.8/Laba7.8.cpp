//Задание 8. Брюс недавно получил работу в NEERC(Numeric Expression Engineering &
//    Research Center), где изучают и строят много различных любопытных
//    чисел.Его первым заданием стало исследование двудесятичных чисел.
//    Натуральное число называется двудесятичным, если его десятичное
//    представление является суффиксом его двоичного представления; и
//    двоичное и десятичное представление рассматривается без ведущих
//    нулей.Например, 1010 = 10102, так что 10 двудесятичное число.Числа
//    101010 = 11111100102 и 4210 = 1010102 не являются двудесятичными.
//    Сначала Брюс хочет создать список двудесятичных чисел.Помогите
//    ему найти n - ое наименьшее двудесятичное число.
//    Выполнил Коновалюк М.А.
#include <iostream>
using namespace std;

unsigned long long NumberOfLeadingZeros(unsigned long long i) {
    int res = 31;
    while (!((i >> res) & 1)) {
        --res;
    }
    return 31ULL - res;
}

unsigned long long solve(unsigned long long n) {
    unsigned long long answer;
    unsigned long long* p = new unsigned long long[19];
    p[0] = 1;
    for (int i = 1; i < 19; i++) {
        p[i] = p[i - 1] * 10;
    }
    unsigned long long k = 0;
    for (unsigned long long i = 1;; i++) {
        unsigned long long cur = 0;
        unsigned long long len = 32 - NumberOfLeadingZeros(i);
        for (unsigned long long j = 0; j < len; j++) {
            if ((i & (1ULL << j)) != 0) {
                cur += p[j];
            }
        }
        if ((cur & ((1ULL << len) - 1)) == i) {
            k++;
            if (k == n) {
                answer = cur;
                break;
            }
        }
    }
    return answer;
}

int main() {
    unsigned long long n;
    std::cin >> n;
    std::cout << solve(n) << '\n';
    return 0;
}