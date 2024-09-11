#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, r, result = 1;
	std::cin >> n >> r;
	for (long long i = n - r + 1; i < n + 1; i++) {
		result *= i;
	}
	std::cout << result << '\n';

	return 0;
}
