#include <string>
#include <iostream>
#include "pch.h"
#include "../../Laba7/MyFuckingString/MyFuckingString.cpp"

// ÔÓÍÊÖÈÈ ÄËß ÒÅÑÒÀ ÏÅĞÂÎÉ ÒÀÑÊÈ

my_str Converter17(long double sum, my_str sign) {
	// ÏÅĞÅÂÎÆÓ Â 17 ÑÑ ÖÅËÓŞ ×ÀÑÒÜ ×ÈÑËÀ

	my_str res = "";
	long long num = sum;
	double ost = sum - num;
	int p;
	while (num) {
		p = num % 17;
		if (p == 10)
			res += 'A';
		else if (p == 11)
			res += 'B';
		else if (p == 12)
			res += 'C';
		else if (p == 13)
			res += 'D';
		else if (p == 14)
			res += 'E';
		else if (p == 15)
			res += 'F';
		else if (p == 16)
			res += 'G';
		else if (p == 17)
			res += 'H';
		else if (p == 0)
			res += '0';
		else {
			res += (char)(p + 48);
		}
		num /= 17;
	}

	// ÏÅĞÅÂÎĞÀ×ÈÂÀŞ ÑÒĞÎÊÓ

	my_str res_i;
	for (int i = 0; i < res.size(); i++) {
		res_i += res[res.size() - i - 1];
	}
	res = "";

	// ÏÅĞÅÂÎÆÓ Â 17 ÑÑ ÄĞÎÁÍÓŞ ×ÀÑÒÜ ×ÈÑËÀ
	int c = 0;
	while (c != 9) {
		++c;
		p = ost * 17;
		ost *= 17;
		ost -= p;
		if (p == 10)
			res += 'A';
		else if (p == 11)
			res += 'B';
		else if (p == 12)
			res += 'C';
		else if (p == 13)
			res += 'D';
		else if (p == 14)
			res += 'E';
		else if (p == 15)
			res += 'F';
		else if (p == 16)
			res += 'G';
		else if (p == 17)
			res += 'H';
		else if (p == 0)
			res += '0';
		else {
			res += (char)(p + 48);
		}
	}
	return sign + res_i + "." + res;
}

my_str Converter10(my_str num_9) {

	// ÏĞÎÑ×ÈÒÛÂÀŞ ÊÎËÈ×ÅÑÒÂÎ ×ÈÑÅË ÄÎ ÒÎ×ÊÈ

	if (num_9[0] == '0') {
		return "0";
	}
	my_str sign = "";
	if (num_9[0] == '-') {
		sign += '-';
	}

	int counter1 = 0, counter2 = 0;
	long double sum = 0;
	for (int i = 0; i < num_9.size(); i++) {
		if (num_9[i] == '-')
			continue;
		if (num_9[i] == '.')
			break;
		++counter1;
	}
	--counter1;
	bool temp = false;
	for (int i = 0; i < num_9.size(); i++) {
		if (num_9[i] == '-')
			continue;
		if (num_9[i] == '.') {
			temp = true;
			continue;
		}
		if ((char)num_9[i] < 48 || (char)num_9[i] > 57) {
			std::cout << "Wrong input! Please, try again!";
			break;
		}
		if (!temp) {
			sum += ((long double)num_9[i] - 48) * pow(9, counter1);
			--counter1;
		}
		else {
			--counter2;
			sum += ((long double)num_9[i] - 48) * pow(9, counter2);
		}
	}
	return Converter17(sum, sign);
}
// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÂÒÎĞÎÉ ÒÀÑÊÈ

my_str Task2(my_str s) {
	if (s[0] == '0')
		return s;
	else {
		for (int i = 2; i < s.size(); i++) {
			if (s[i] == '0')
				s[i] = '1';
			else if (s[i] == '1')
				s[i] = '0';
		}
		int brain = 1;
		for (int i = s.size() - 1; i > 1; i--) {
			if (s.ctoi(s[i]) && brain) {
				s[i] = '0';
			}
			else if (brain && !s.ctoi(s[i])) {
				s[i] = '1';
				break;
			}
		}
		return s;
	}
}


// ÔÓÍÊÖÈÈ ÄËß ÒÅÑÒÀ ÒĞÅÒÜÅÉ ÒÀÑÊÈ

my_str new_code(my_str& s) {
	if (s[0] == '0')
		return s;
	else {
		for (int i = 2; i < s.size(); i++) {
			if (s[i] == '0')
				s[i] = '1';
			else if (s[i] == '1')
				s[i] = '0';
		}
		int brain = 1;
		for (int i = s.size() - 1; i > 1; i--) {
			if (s.ctoi(s[i]) && brain) {
				s[i] = '0';
			}
			else if (brain && !s.ctoi(s[i])) {
				s[i] = '1';
				break;
			}
		}
		return s;
	}
}

my_str Sum(my_str s1, my_str s2) {
	s1.reverse();
	s2.reverse();
	int brain = 0;
	my_str sum;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '.') {
			sum += '.';
		}
		else {
			int num1 = s1[i] - '0';
			int num2 = s2[i] - '0';
			sum += (num1 + num2 + brain) % 2 + '0';
			brain = (num1 + num2) / 2;
		}
	}

	sum.reverse();
	return sum;
}

my_str Solver(my_str string1, my_str string2) {
	string1.reverse();
	string2.reverse();
	int k = 0, counter1 = 0, counter2 = 0;

	my_str str1, str2;
	while (string1[k] != '.' && string1[k] != ',') {
		str1 += string1[k];
		++k;
	}
	k = 0;
	while (string2[k] != '.' && string2[k] != ',') {
		str2 += string2[k];
		++k;
	}

	if (str1.size() > str2.size()) {
		while (str1.size() != str2.size()) {
			str2 += '0';
		}
		str1 += string1[string1.size() - 1];
		str2 += string2[string2.size() - 1];
	}
	else if (str2.size() > str1.size()) {
		while (str1.size() != str2.size()) {
			str1 += '0';
		}
		str1 += '.';
		str2 += '.';
		str1 += string1[string1.size() - 1];
		str2 += string2[string2.size() - 1];
	}
	else {
		str1 += '.';
		str2 += '.';
		str1 += string1[string1.size() - 1];
		str2 += string2[string2.size() - 1];
	}

	str1.reverse();
	str2.reverse();

	new_code(str1);
	new_code(str2);

	//std::cout << "s1 " << str1 << " s2 " << str2 << '\n';
	my_str res = Sum(str1, str2);
	return res;
}

// ÔÓÍÊÖÈÈ ÄËß ÒÅÑÒÀ ×ÅÒÂÅĞÒÎÉ ÒÀÑÊÈ

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
		result += code17[(num1 + num2 + d) % 17];
		d = (num1 + num2 + d) / 17;
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
		result += code17[(num1 - num2 + d + 17) % 17];
		d = (num1 - num2 + d - 16) / 17;
	}
	result.reverse();
	return result;
}

// ÔÓÍÊÖÈÈ ÄËß ÒÅÑÒÀ ÏßÒÎÉ ÒÀÑÊÈ

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

	if (((ar_num < 0) || (ar_num > 3999))) { //4000 - çíàêè, êîòîğûõ íåò íà êëàâå 
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

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ØÅÑÒÎÉ ÒÀÑÊÈ

long long Task6(long long n) {
	return (n + 1) / 10;
}

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÑÅÄÜÌÎÉ ÒÀÑÊÈ
my_str Devider(long long in, int counter) {
	bool isDiv = false;
	long long tmp = in;
	long long var = 0;
	while (tmp >= var) {
		while (!(tmp & 1))
			tmp >>= 1;
		if (tmp == var) {
			isDiv = true;
			break;
		}
		var += counter;
	}
	if (isDiv) {
		return "The num devides";
	}
	else {
		return "The num don't devides";
	}
}

// ÔÓÍÊÖÈÈ ÄËß ÒÅÑÒÀ ÂÎÑÜÌÎÉ ÒÀÑÊÈ

unsigned long long NumberOfLeadingZeros(unsigned long long k) {
	int res = 31;
	while (!((k >> res) & 1)) {
		--res;
	}
	return 31ULL - res;
}

unsigned long long Task8(unsigned long long n) {
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

// ÔÓÍÊÖÈß ÄËß ÒÅÑÒÀ ÄÅÂßÒÎÉ ÒÀÑÊÈ

my_str Task9(int n) {
	int temp = 1;
	int length = 0;
	while (n / temp > 0) {
		temp *= 3;
		++length;
	}

	temp /= 3;
	int* arr = new int[length];
	int position = 0;
	my_str result = "";

	while (temp) {
		arr[position] = n / temp;
		n %= temp;
		temp /= 3;
		int l = position;
		while (arr[l] == 0 && l != 0) {
			arr[l] = 3;
			--l;
			--arr[l];
		}
		++position;
	}

	for (int i = 0; i < length; i++) {
		if (arr[i] == 0 && i != 0)
			break;
		else if (arr[i] != 0) {
			result += arr[i] + '0';
		}
	}

	delete[] arr;

	return result;
}


TEST(Task1, Test1) {
	my_str expected = "1BC7.4E10E4A86";
	my_str obtained = Converter10("12345.25");
	EXPECT_EQ(expected, obtained);
}

TEST(Task1, Test2) {
	my_str expected = "0";
	my_str obtained = Converter10("0");
	EXPECT_EQ(expected, obtained);
}

TEST(Task1, Test3) {
	my_str expected = "-574.000000000";
	my_str obtained = Converter10("-2132");
	EXPECT_EQ(expected, obtained);
}

TEST(Task1, Test4) {
	my_str expected = "1.072543617";
	my_str obtained = Converter10("1.02");
	EXPECT_EQ(expected, obtained);
}

TEST(Task2, Test1) {
	my_str expected = "0.001";
	my_str obtained = Task2("0.001");
	EXPECT_EQ(expected, obtained);
}

TEST(Task2, Test2) {
	my_str expected = "0.000";
	my_str obtained = Task2("0.000");
	EXPECT_EQ(expected, obtained);
}

TEST(Task2, Test3) {
	my_str expected = "1.111";
	my_str obtained = Task2("1.001");
	EXPECT_EQ(expected, obtained);
}

TEST(Task2, Test4) {
	my_str expected = "1.111";
	my_str obtained = Task2("1.001");
	EXPECT_EQ(expected, obtained);
}

TEST(Task3, Test1) {
	my_str expected = "0.011";
	my_str obtained = Solver("0.001", "0.010");
	EXPECT_EQ(expected, obtained);
}

TEST(Task3, Test2) {
	my_str expected = "1.111";
	my_str obtained = Solver("1.100", "0.011");
	EXPECT_EQ(expected, obtained);
}

TEST(Task3, Test3) {
	my_str expected = "0.010";
	my_str obtained = Solver("0.001", "0.001");
	EXPECT_EQ(expected, obtained);
}

TEST(Task3, Test4) {
	my_str expected = "0.0001";
	my_str obtained = Solver("1.1111", "1.0000");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSum1) {
	my_str expected = "26";
	my_str obtained = sum("F", "18");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSum2) {
	my_str expected = "0F";
	my_str obtained = sum("-A", "-5");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSum3) {
	my_str expected = "A68";
	my_str obtained = sum("6FB", "37E");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSum4) {
	my_str expected = "5E";
	my_str obtained = sum("0", "5E");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSub1) {
	my_str expected = "2G";
	my_str obtained = sub("5F", "2G");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSub2) {
	my_str expected = "0";
	my_str obtained = sub("9", "9");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSub3) {
	my_str expected = "2D1";
	my_str obtained = sub("37E", "BD");
	EXPECT_EQ(expected, obtained);
}

TEST(Task4, TestSub4) {
	my_str expected = "55";
	my_str obtained = sub("5A", "5");
	EXPECT_EQ(expected, obtained);
}

TEST(Task5, Test1) {
	my_str expected = "MMIX";
	my_str obtained = Convert(2009);
	EXPECT_EQ(expected, obtained);
}

TEST(Task5, Test2) {
	my_str expected = "D";
	my_str obtained = Convert(500);
	EXPECT_EQ(expected, obtained);
}

TEST(Task5, Test3) {
	my_str expected = "XLIX";
	my_str obtained = Convert(49);
	EXPECT_EQ(expected, obtained);
}

TEST(Task5, Test4) {
	my_str expected = "CMXCIX";
	my_str obtained = Convert(999);
	EXPECT_EQ(expected, obtained);
}

TEST(Task5, Test5) {
	my_str expected = "VIII";
	my_str obtained = Convert(8);
	EXPECT_EQ(expected, obtained);
}

TEST(Task6, Test1) {
	long long expected = 0;
	long long obtained = Task6(1);
	EXPECT_EQ(expected, obtained);
}

TEST(Task6, Test2) {
	long long expected = 1;
	long long obtained = Task6(9);
	EXPECT_EQ(expected, obtained);
}

TEST(Task6, Test3) {
	long long expected = 1;
	long long obtained = Task6(10);
	EXPECT_EQ(expected, obtained);
}

TEST(Task6, Test4) {
	long long expected = 3;
	long long obtained = Task6(34);
	EXPECT_EQ(expected, obtained);
}

TEST(Task6, Test5) {
	long long expected = 88005553;
	long long obtained = Task6(880055535);
	EXPECT_EQ(expected, obtained);
}

TEST(Task7, Test1) {
	my_str expected = "The num devides";
	my_str obtained = Devider(30,3);
	EXPECT_EQ(expected, obtained);
}

TEST(Task7, Test2) {
	my_str expected = "The num devides";
	my_str obtained = Devider(94, 47);
	EXPECT_EQ(expected, obtained);
}

TEST(Task7, Test3) {
	my_str expected = "The num devides";
	my_str obtained = Devider(394, 197);
	EXPECT_EQ(expected, obtained);
}

TEST(Task7, Test4) {
	my_str expected = "The num don't devides";
	my_str obtained = Devider(2, 3);
	EXPECT_EQ(expected, obtained);
}

TEST(Task7, Test5) {
	my_str expected = "The num don't devides";
	my_str obtained = Devider(28, 47);
	EXPECT_EQ(expected, obtained);
}

TEST(Task7, Test6) {
	my_str expected = "The num don't devides";
	my_str obtained = Devider(198, 197);
	EXPECT_EQ(expected, obtained);
}

TEST(Task8, Test1) {
	unsigned long long expected = 1;
	unsigned long long obtained = Task8(1);
	EXPECT_EQ(expected, obtained);
}

TEST(Task8, Test2) {
	unsigned long long expected = 10;
	unsigned long long obtained = Task8(2);
	EXPECT_EQ(expected, obtained);
}

TEST(Task8, Test3) {
	unsigned long long expected = 1100;
	unsigned long long obtained = Task8(10);
	EXPECT_EQ(expected, obtained);
}

TEST(Task9, Test1) {
	my_str expected = "21";
	my_str obtained = Task9(7);
	EXPECT_EQ(expected, obtained);
}

TEST(Task9, Test2) {
	my_str expected = "211";
	my_str obtained = Task9(22);
	EXPECT_EQ(expected, obtained);
}

TEST(Task9, Test3) {
	my_str expected = "13332";
	my_str obtained = Task9(200);
	EXPECT_EQ(expected, obtained);
}

TEST(Task9, Test4) {
	my_str expected = "123112";
	my_str obtained = Task9(500);
	EXPECT_EQ(expected, obtained);
}

TEST(Task9, Test5) {
	my_str expected = "1";
	my_str obtained = Task9(1);
	EXPECT_EQ(expected, obtained);
}