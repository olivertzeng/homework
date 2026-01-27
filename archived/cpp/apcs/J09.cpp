#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long mid, costSum = 0, n, sum = 0;
	std::cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (auto var : a) {
		sum += var;
	}
	std::sort(a, a + n);

	mid = a[n / 2];
	for (auto var : a) {
		costSum += llabs(var - mid);
	}
	std::cout << costSum << "\n";
	return 0;
}
