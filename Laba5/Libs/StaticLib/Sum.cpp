#include "Header.h"
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