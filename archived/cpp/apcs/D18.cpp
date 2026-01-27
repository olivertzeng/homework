#include <algorithm>
#include <iostream>
#include <utility>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long a, b, sum;
	std::cin >> a >> b;
	if (b < a)
		std::swap(a, b);
	a += a % 2;
	b -= b % 2;
	sum = (a + b) / 2 * ((b - a) / 2 + 1);
	std::cout << sum << '\n';

	return 0;
}
