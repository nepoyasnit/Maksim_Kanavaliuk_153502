#include "pch.h"
#include <string>

//ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÏÅĞÂÎÉ ÒÀÑÊÈ
char Task1(char a) {
    if ((int)(a - 48) % 2 == 0 && a != ' ' && a - 48 != 0) {
        return a;
    }
    return '0';
}

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÂÒÎĞÎÉ ÒÀÑÊÈ
std::string Task2_max(std::string str) {
    int length = str.size();
    int maxLength = 0, counter = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != ' ')
            ++counter;
        else {
            if (counter > maxLength)
                maxLength = counter;
            counter = 0;
        }
    }
    if (counter > maxLength)
        maxLength = counter;

    int temp = 0, start = 0;
    std::string answ = "";

    for (int i = 0; i < length; i++) {
        if (!start || str[i - 1] == ' ') {
            temp = 0;
            for (int j = i; str[j] != ' ' && str[j] != '\0'; j++) {
                ++temp;
            }
        }
        if (temp == maxLength) {
            answ += str[i];
        }
        ++start;
    }
    return answ;
}

std::string Task2_min(std::string str) {
    int length = str.size();
    int minLength = 1e9, counter = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != ' ')
            ++counter;
        else {
            if (counter > 0 && counter < minLength)
                minLength = counter;
            counter = 0;
        }
    }
    if (counter > 0 && counter < minLength)
        minLength = counter;

    int temp = 0, start = 0;
    std::string answ = "";

    for (int i = 0; i < length; i++) {
        if (!start || str[i - 1] == ' ') {
            temp = 0;
            for (int j = i; str[j] != ' ' && str[j] != '\0'; j++) {
                ++temp;
            }
        }
        if (temp == minLength) {
            answ += str[i];
        }
        ++start;
    }
    return answ;
}

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÒĞÅÒÜÅÉ ÒÀÑÊÈ

bool Palindrom(std::string s) {
    int l = s.size();
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

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ×ÅÒÂ¨ĞÒÎÉ ÒÀÑÊÈ

std::string Task4(std::string str) {
    int new_length = 0;
    std::string new_str = "";
    int length = str.size();
    for (int i = 0, j = 0; i < length; i++, j++) {
        if ((str[i] == 'c') && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
            new_str += 's';
            new_length++;
        }
        else if ((str[i] == 'C') && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
            new_str += 'S';
            new_length++;
        }
        else if (str[i] == 'c') {
            new_str += 'k';
            new_length++;
        }
        else if (str[i] == 'C') {
            new_str += 'K';
            new_length++;
        }
        else if (str[i] == 'q' && str[i + 1] == 'u') {
            new_str += 'k';
            new_str += 'v';
            new_length += 2;
            ++i;
            ++j;
        }
        else if (str[i] == 'Q' && str[i + 1] == 'u') {
            new_str += 'K';
            new_str += 'v';
            new_length += 2;
            ++i;
            ++j;
        }
        else if (str[i] == 'q') {
            new_str += 'k';
            new_length++;
        }
        else if (str[i] == 'Q') {
            new_str += 'K';
            new_length++;
        }
        else if (str[i] == 'x') {
            new_str += 'k';
            new_str += 's';
            new_length += 2;
            ++j;
        }
        else if (str[i] == 'X') {
            new_str += 'K';
            new_str += 's';
            new_length += 2;
            ++j;
        }
        else if (str[i] == 'w') {
            new_str += 'v';
            new_length++;
        }
        else if (str[i] == 'W') {
            new_str += 'V';
            new_length++;
        }
        else if (str[i] == 'p' && str[i + 1] == 'h') {
            new_str += 'f';
            new_length++;
            ++i;
        }
        else if (str[i] == 'P' && str[i + 1] == 'h') {
            new_str += 'F';
            new_length++;
            ++i;
        }
        else if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
            new_str += 'u';
            new_length++;
            i += 2;
        }
        else if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
            new_str += 'U';
            new_length++;
            i += 2;
        }
        else if (str[i] == 'o' && str[i + 1] == 'o') {
            new_str += 'u';
            new_length++;
            ++i;
        }
        else if (str[i] == 'O' && str[i + 1] == 'o') {
            new_str += 'U';
            new_length++;
            ++i;
        }
        else if (str[i] == 'e' && str[i + 1] == 'e') {
            new_str += 'i';
            new_length++;
            ++i;
        }
        else if (str[i] == 'E' && str[i + 1] == 'e') {
            new_str += 'I';
            new_length++;
            ++i;
        }
        else if (str[i] == 't' && str[i + 1] == 'h') {
            new_str += 'z';
            new_length++;
            ++i;
        }
        else if (str[i] == 'T' && str[i + 1] == 'h') {
            new_str += 'Z';
            new_length++;
            ++i;
        }
        else if (str[i] == str[i + 1]) {
            new_str += str[i];
            new_length++;
            ++i;
        }
        else {
            new_str += str[i];
            new_length++;
        }
    }
    std::string answ = "";

    for (int i = 0; i < new_length; i++) {
        if (i == new_length - 1) {
            answ += new_str[i];
        }
        else {
            if (new_str[i] == new_str[i + 1])
                continue;
            else
                answ += new_str[i];
        }
    }

    return answ;
}

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ØÅÑÒÎÉ ÒÀÑÊÈ

long double factorial(int n) {
    long double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int Task6(std::string str) {
    int length = str.size();
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
    return answ;
}

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ 7É ÒÀÑÊÈ

int Task7(std::string str) {
    int length = str.size();
    bool temp = true;
    for (int i = 1; i < length; i++) {
        if (str[i] != str[0]) {
            temp = false;
            break;
        }
        else {
            temp = true;
        }
    }
    if (temp) {
        return -1;
    }
    int j = 0;

    // Ïğîâåğêà íà ïàëèíäğîì 

    temp = true;
    for (int i = length - 1; i >= 0; i--) {
        for (j = 0; j <= i / 2; j++) {
            if (str[j] != str[i - j]) {
                temp = false;
                break;
            }
        }
        if (!temp) {
            return i + 1;
        }
    }
    return -1;
}

std::string Task8(std::string str1, std::string str2) {
    int length1 = str1.size();
    int length2 = str2.size();
    bool isFound = false;
    for (int i = 0; i < length1; ++i)
    {
        int j = 0;
        for (int dist = 0; dist < length1 - i; ++dist)
        {
            int itemp = i;
            j = 0;
            int checked = 0;
            for (int k = 0; k <= dist; ++k) {
                if (str1[i + k] == str2[j]) {
                    j++;
                }
                else {
                    checked = 1;
                    break;
                }
                if (j == length2) {
                    isFound = 1;
                    break;
                }
            }
            if (checked) {
                i = itemp;
                break;

            }
            if (isFound) {
                break;

            }
            i = i + dist - 1;
            int jtemp = j;
            for (; i >= 0; --i) {
                if (str1[i] == str2[j]) {
                    j++;
                }
                else {
                    checked = 1;
                    break;
                }
                if (j == length2) {
                    isFound = 1;
                    break;
                }
            }
            if (checked) {
                i = itemp;
                continue;
            }
            if (isFound) {
                break;
            }
            i = itemp;
        }

    }
    if (isFound) {
        return "YES";
    }
    else {
        return "NO";
    }
}

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÄÅÂßÒÎÉ ÒÀÑÊÈ

double Task9(std::string str) {
    double sum_d = 0;
    int sum_i = 0;
    int length = str.size();

    for (int i = 0; i < length; i++) {
        int last_sum = 0;
        if ((int)str[i] >= 48 && (int)str[i] <= 57) {
            //sum_i += (int)str[i] - 48;
            int j = 0;
            int temp = 1;
            int counter = i;
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
            // ÏĞÎÂÅĞÊÀ ×ÈÑÅË ÑËÅÂÀ ÎÒ ÒÎ×ÊÈ
            while ((int)str[counter] >= 48 && (int)str[counter] <= 57) {
                left += ((double)str[counter] - 48) * temp;
                //sum_i -= left / temp;
                temp *= 10;

                --counter;
            }
            temp = 10;
            counter = i + 1;
            int j = 0;
            // ÏĞÎÂÅĞÊÀ ×ÈÑÅË ÑÏĞÀÂÀ ÎÒ ÒÎ×ÊÈ
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
            sum_d += right + left;
        }
    }

    return (double)sum_i + sum_d;
}

// ÒÅÑÒÛ

// ÒÅÑÒÛ ÄËß ÏÅĞÂÎÉ ÒÀÑÊÈ

TEST(TestCase1, task1) {
    char expected = Task1('8');
    char obtained = '8';
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase2, task1) {
    char expected = Task1('a');
    char obtained = '0';
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase3, task1) {
    char expected = Task1('3');
    char obtained = '0';
    EXPECT_EQ(expected, obtained);
}

//ÒÅÑÒÛ ÂÒÎĞÀß ÒÀÑÊÀ ÌÀÊÑÈÌÓÌ

TEST(TestCaseMaximal1, task2) {
    std::string obtained = Task2_max("dada dada ds");
    std::string expected = "dada dada ";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCaseMaximal2, task2) {
    std::string obtained = Task2_max("qwertyuiopasdfghjklzxcvbnm1234567890 a");
    std::string expected = "qwertyuiopasdfghjklzxcvbnm1234567890 ";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCaseMaximal3, task2) {
    std::string obtained = Task2_max("a a");
    std::string expected = "a a";
    EXPECT_EQ(expected, obtained);
}

 //ÒÅÑÒÛ ÂÒÎĞÀß ÒÀÑÊÀ ÌÈÍÈÌÓÌ

TEST(TestCaseMinimal1, task2) {
    std::string obtained = Task2_min("dada dada ds");
    std::string expected = "ds";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCaseMinimal2, task2) {
    std::string obtained = Task2_min("a a a");
    std::string expected = "a a a";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCaseMinimal3, task2) {
    std::string obtained = Task2_min("qwertyuiopasdfghjklzxcvbnm12345670 qwertyuiopasdfghjklzxcvbnm123456789");
    std::string expected = "qwertyuiopasdfghjklzxcvbnm12345670 ";
    EXPECT_EQ(expected, obtained);
}

// ÒÅÑÒÛ ÄËß ÒĞÅÒÜÅÉ ÒÀÑÊÈ

TEST(TestCase1, task3) {
    bool obtained = Palindrom("a roza upala na lapu azora");
    bool expected = true;
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase2, task3) {
    bool obtained = Palindrom("argentina manit ne gra");
    bool expected = true;
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase3, task3) {
    bool obtained = Palindrom("a  a madam a ");
    bool expected = false;
    EXPECT_EQ(expected, obtained);
}

// ×ÅÒÂ¨ĞÒÀß ÒÀÑÊÀ

TEST(TestCase1, task4) {
    std::string obtained = Task4("Too swift for Theex, too quick for Gallow");
    std::string expected = "Tu svift for Ziks, tu kvik for Galov";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase2, task4) {
    std::string obtained = Task4("Too strong for young Prince Joseph to follow");
    std::string expected = "Tu strong for ung Prinse Josef to folov";
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase3, task4) {
    std::string obtained = Task4("kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");
    std::string expected = "k";
    EXPECT_EQ(expected, obtained);
}

// ÒÅÑÒÛ ÄËß ØÅÑÒÎÉ ÒÀÑÊÈ

TEST(TestCase1, task6) {
    int obtained = Task6("SOLO");
    int expected = 12;
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase2, task6) {
    long double obtained = Task6("ooooooooooooooooooooooo");
    long double expected = 1;
    EXPECT_EQ(expected, obtained);
}

TEST(TestCase3, task6) {
    int obtained = Task6("helicopter");
    int expected = 1814400;
    EXPECT_EQ(expected, obtained);
}

// ÒÅÑÒÛ ÄËß ÑÅÄÜÌÎÉ ÒÀÑÊÈ

TEST(TestCase1, task7) {
    int obtained = Task7("madam");
    int expected = 4;
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase2, task7) {
    int obtained = Task7("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    int expected = -1;
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase3, task7) {
    int obtained = Task7("argentinamanitnegra");
    int expected = 18;
    EXPECT_EQ(expected, obtained);
}

// ÒÅÑÒÛ ÂÎÑÜÌÎÉ ÒÀÑÊÈ

TEST(TestCase1, task8) {
    std::string obtained = Task8("abcdef", "cdedcb");
    std::string expected = "YES";
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase2, task8) {
    std::string obtained = Task8("aaa", "aaaaa");
    std::string expected = "YES";
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase3, task8) {
    std::string obtained = Task8("aab", "baaa");
    std::string expected = "NO";
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase4, task8) {
    std::string obtained = Task8("ab", "b");
    std::string expected = "YES";
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase5, task8) {
    std::string obtained = Task8("abcdef", "abcdef");
    std::string expected = "YES";
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase6, task8) {
    std::string obtained = Task8("ba", "baa");
    std::string expected = "NO";
    EXPECT_EQ(expected, obtained);
}

// ÒÅÑÒÛ ÄÅÂßÒÎÉ ÒÀÑÊÈ

TEST(TestCase1, task9) {
    double obtained = Task9("a3.141592das2");
    double expected = 5.141592;
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase2, task9) {
    double obtained = Task9("s2s2s2s2s2");
    double expected = 10;
    EXPECT_EQ(expected, obtained);
}
TEST(TestCase3, task9) {
    double obtained = Task9("jj12.15ha3.45l");
    double expected = 15.6;
    EXPECT_NEAR(expected, obtained,0.001);
}