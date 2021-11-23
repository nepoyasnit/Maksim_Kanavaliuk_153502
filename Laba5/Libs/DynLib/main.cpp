#include <cmath>
#include "Header.h"
extern "C" __declspec(dllexport) int elements(int* a, int n, int& sum) {
	if (n < 0)
		return sum;
	sum = (cos(a[n] * a[n]) > 0) ^ (a[n] < 0) + elements(a, n - 1, sum);
}