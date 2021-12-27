//Задача 4
//1 апреля 20 ? ? года будет проведена реформа английского языка,
//позволяющая облегчить его освоение иностранцами и английскими
//школьниками.Во - первых, из алфавита уберут четыре буквы C, Q, W и X(на
//    клавиатуре компьютера вместо них будут клавиши, вызывающие программы
//    Word, eXcel и другие).Вместо c перед буквами e, i, y нужно будет писать
//    букву s, а в остальных случаях – букву k.Вместо буквы q нужно будет писать
//    букву k, вместо сочетания qu –
//    kv, вместо x – ks, а вместо w – v.Во - вторых, сочетание букв ph будет
//    записываться как f, you и oo – как u, ee – как i, th – как z.Кроме того, все
//    двойные согласные(включая образовавшиеся после замен), вызывающие
//    большие трудности у учащихся, станут одинарными, например, apple после
//    реформы нужно писать как aple.
//    В связи с реформой нужно переработать огромное количество текстов.
//    Напишите программу, выполняющую эту работу.
//    Выполнил Коновалюк М.А.

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

    char* new_str = (char*)malloc(length * 2 * sizeof(char));
    int new_length = 0;

    for (int i = 0, j = 0; i < length; i++, j++) {
        if ((str[i] == 'c') && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
            new_str[j] = 's';
            new_length++;
        }
        else if ((str[i] == 'C') && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
            new_str[j] = 'S';
            new_length++;
        }
        else if (str[i] == 'c') {
            new_str[j] = 'k';
            new_length++;
        }
        else if (str[i] == 'C') {
            new_str[j] = 'K';
            new_length++;
        }
        else if (str[i] == 'q' && str[i + 1] == 'u') {
            new_str[j] = 'k';
            new_str[j + 1] = 'v';
            new_length += 2;
            ++i;
            ++j;
        }
        else if (str[i] == 'Q' && str[i + 1] == 'u') {
            new_str[j] = 'K';
            new_str[j + 1] = 'v';
            new_length += 2;
            ++i;
            ++j;
        }
        else if (str[i] == 'q') {
            new_str[j] = 'k';
            new_length++;
        }
        else if (str[i] == 'Q') {
            new_str[j] = 'K';
            new_length++;
        }
        else if (str[i] == 'x') {
            new_str[j] = 'k';
            new_str[j + 1] = 's';
            new_length += 2;
            ++j;
        }
        else if (str[i] == 'X') {
            new_str[j] = 'K';
            new_str[j + 1] = 's';
            new_length += 2;
            ++j;
        }
        else if (str[i] == 'w') {
            new_str[j] = 'v';
            new_length++;
        }
        else if (str[i] == 'W') {
            new_str[j] = 'V';
            new_length++;
        }
        else if (str[i] == 'p' && str[i + 1] == 'h') {
            new_str[j] = 'f';
            new_length++;
            ++i;
        }
        else if (str[i] == 'P' && str[i + 1] == 'h') {
            new_str[j] = 'F';
            new_length++;
            ++i;
        }
        else if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
            new_str[j] = 'u';
            new_length++;
            i += 2;
        }
        else if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
            new_str[j] = 'U';
            new_length++;
            i += 2;
        }
        else if (str[i] == 'o' && str[i + 1] == 'o') {
            new_str[j] = 'u';
            new_length++;
            ++i;
        }
        else if (str[i] == 'O' && str[i + 1] == 'o') {
            new_str[j] = 'U';
            new_length++;
            ++i;
        }
        else if (str[i] == 'e' && str[i + 1] == 'e') {
            new_str[j] = 'i';
            new_length++;
            ++i;
        }
        else if (str[i] == 'E' && str[i + 1] == 'e') {
            new_str[j] = 'I';
            new_length++;
            ++i;
        }
        else if (str[i] == 't' && str[i + 1] == 'h') {
            new_str[j] = 'z';
            new_length++;
            ++i;
        }
        else if (str[i] == 'T' && str[i + 1] == 'h') {
            new_str[j] = 'Z';
            new_length++;
            ++i;
        }
        else if (str[i] == str[i + 1]) {
            new_str[j] = str[i];
            new_length++;
            ++i;
        }
        else {
            new_str[j] = str[i];
            new_length++;
        }
    }



    for (int i = 0; i < new_length ; i++) {
        if (new_str[i] == new_str[i + 1])
            continue;
        std::cout << new_str[i];
    }

    free(str);
    free(new_str);
}

int main()
{
	Solve();

	return 0;
}
