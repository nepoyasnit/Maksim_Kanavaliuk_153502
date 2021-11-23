#include <gtest/gtest.h>
#include "..\StaticLib\Header.h"

int F(int n) {
	if (n % 10 > 0)
		return n % 10;
	else if (!n)
		return 0;
	else
		return F(n / 10);
}

int S(int p, int q, int& sum) {
	if (p <= q) {
		sum += F(p);
		return S(p + 1, q, sum);
	}
	return sum;
}

int Sum(int n) {
	if (n % 2 != 0) {
		return n;
	}
	else {
		while (n % 2 == 0)
			n /= 2;
		return n;
	}
}

TEST(TestCaseF1, task2) {
	double expected = 1;
	double obtained = F(1);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(TestCaseF2, task2) {
	double expected = 1;
	double obtained = F(1000000000);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(TestCaseF3, task2) {
	double expected = 0;
	double obtained = F(0);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(TestCaseS1, task2) {
	int sum = 0;
	double expected = 5;
	double obtained = S(2,3, sum);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(TestCaseS2, task2) {
	int sum = 0;
	double expected = 46;
	double obtained = S(0,10,sum);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(Sum1, task6) {
	double expected = 300000001;
	double obtained = Sum(300000001);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(Sum2, task6) {
	double expected = 150000001;
	double obtained = Sum(300000002);
	ASSERT_DOUBLE_EQ(expected, obtained);
}

TEST(Sum3, task6) {
	double expected = 1;
	double obtained = Sum(2);
	ASSERT_DOUBLE_EQ(expected, obtained);
}