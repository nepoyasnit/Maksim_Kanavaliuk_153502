//TASK 5
/*Во многих прикладных задачах, таких как поиск в сети или расшифровка генома, требуется совершать некоторые действия со строками.
Например, часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом искомой строки S, а другая — ее префиксом.
Также известна длина искомой строки L, а также то, что строка S состояла только из строчных букв латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим ограничениям. Так как это число может быть*/

// Выполнил Коновалюк Максим 153502

#include <iostream>
char* CharSum(char* a, char* b, int l1, int l2) {
    char* c = new char[l1 + l2 + 1];
    for (int i = 0; i < l1; ++i) {
        c[i] = a[i];
    }
    for (int i = l1; i < l1 + l2; ++i) {
        c[i] = b[i - l1];
    }
    return c;
}

bool isEq(char* s1, char* s2, int l1) {
    bool isEq = true;
    for (int i = 0; i < l1; ++i) {
        if (s1[i] != s2[i]) {
            isEq = false;
        }
    }
    return isEq;
}

int pow(int k, int n, int mod) {
    k %= mod;
    if (n == 0) {
        return 1 % mod; //k ^ 0
    }
    if (n % 2) {
        return (k * pow((k * k), n / 2, mod)) % mod; //k * k ^ (n - 1)
    }
    return pow((k * k), n / 2, mod) % mod; //k ^ (n / 2) * k ^ (n / 2)
}

int func(char s1[], char s2[], int n, int mod) {
    int l1;
    for (l1 = 0; s1[l1]; ++l1);
    int l2;
    for (l2 = 0; s2[l2]; ++l2);
    if (l1 + l2 == n) {
        char* c1 = CharSum(s1, s2, l1, l2);
        char* c2 = CharSum(s2, s1, l2, l1);
        bool eq = true;
        for (int i = 0; i < l1 + l2; ++i) {
            if (c1[i] != c2[i]) {
                eq = false;
            }
        }
        if (!eq) {
            return 2;
        }
        else {
            return 1;
        }
    }
    else if (l1 + l2 > n) {
        int delta = l1 + l2 - n;
        short flag1 = 1;
        short flag2 = 1;
        for (int i = 0; i < delta; ++i) {
            if (s1[delta - i - 1] != s2[l2 - 1 - i]) {
                flag1 = 0;
            }
            if (s2[delta - i - 1] != s1[l1 - 1 - i]) {
                flag2 = 0;
            }
        }
        if (flag1 && flag2) {
            char* c1 = CharSum(s1, s2, l1 - delta, l2);
            char* c2 = CharSum(s2, s1, l2 - delta, l1);
            bool eq = true;
            for (int i = 0; i < n; ++i) {
                if (c1[i] != c2[i]) {
                    eq = false;
                    break;
                }
            }
            if (!eq) {
                return 2;
            }
            else {
                return 1;
            }
        }
        return (flag1 + flag2) % mod;
    }
    else {
        int delta = n - l1 - l2;
        if (l1 == l2) {
            bool isEq = true;
            for (int i = 0; i < l1; ++i) {
                if (s1[i] != s2[i]) {
                    isEq = false;
                }
            }
            if (isEq) {
                return pow(26, delta, mod) % mod;
            }
            else {
                return pow(26, delta, mod) * 2 % mod;
            }
        }
        else {
            int sz = ((l1 > l2) ? l2 : l1);
            bool isEq1 = true;
            bool isEq2 = true;
            for (int i = 0; i < sz; ++i) {
                if (s1[i] != s2[i]) {
                    isEq1 = false;
                    break;
                }
            }
            for (int i = 0; i < sz; ++i) {
                if (s1[l1 - 1 - i] != s2[l2 - 1 - i]) {
                    isEq2 = false;
                    break;
                }
            }
            if (isEq1 && isEq2) {
                if (l1 > l2) {
                    if (n - 2 * l1 >= 0) {
                        return (pow(26, delta, mod) * 2 + mod - pow(26, n - 2 * l1, mod)) % mod;
                    }
                    if (l1 - 2 * l2 == delta) {
                        return (pow(26, delta, mod) * 2 + mod - 1) % mod;
                    }
                    else if (l1 - 2 * l2 <= delta && l1 - l2 > delta) {
                        int lq = delta - (l1 - 2 * l2);
                        char* q1 = new char[lq];
                        for (int i = 0; i < lq; ++i) {
                            q1[i] = s2[i];
                        }
                        char* q2 = new char[lq];
                        for (int i = 0; i < lq; ++i) {
                            q2[i] = s2[l2 - 1 - i];
                        }
                        bool isp = isEq(CharSum(q1, s2, lq, l2), CharSum(s2, q2, l2, lq), l2 + lq);
                        if (isp) {
                            return (pow(26, delta, mod) * 2 + mod - 1) % mod;
                        }
                        else {
                            return (pow(26, delta, mod) * 2) % mod;
                        }
                    }
                    else {
                        return (pow(26, delta, mod) * 2) % mod;
                    }
                }
                else {
                    if (n - 2 * l2 >= 0) {
                        return (pow(26, delta, mod) * 2 + mod - pow(26, n - 2 * l2, mod)) % mod;
                    }
                    if (l2 - 2 * l1 == delta) {
                        return (pow(26, delta, mod) * 2 - 1) % mod;
                    }
                    else if (l2 - 2 * l1 <= delta && l2 - l1 > delta) {
                        int lq = delta - (l2 - 2 * l1);
                        char* q1 = new char[lq];
                        for (int i = 0; i < lq; ++i) {
                            q1[i] = s1[i];
                        }
                        char* q2 = new char[lq];
                        for (int i = 0; i < lq; ++i) {
                            q2[lq - 1 - i] = s1[l1 - 1 - i];
                        }
                        bool isp = isEq(CharSum(q1, s1, lq, l1), CharSum(s1, q2, l1, lq), l1 + lq);
                        if (isp) {
                            return (pow(26, delta, mod) * 2 + mod - 1) % mod;
                        }
                        else {
                            return (pow(26, delta, mod) * 2) % mod;
                        }
                    }
                    else {
                        return (pow(26, delta, mod) * 2) % mod;
                    }
                }
            }
            else {
                return (pow(26, delta, mod) * 2) % mod;
            }
        }
    }
}



int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, mod;
        std::cin >> n >> mod;
        char s1[201], s2[201];
        
        std::cin >> s1 >> s2;

        std::cout << func(s1, s2, n, mod) % mod << '\n';
    }
    return 0;
}