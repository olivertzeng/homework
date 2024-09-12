#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long a, b, result = 0;
	std::cin >> a >> b;
	for (long long i = a; i < b + 1; i++) {
		result += i;
		if (i == b) {
			std::cout << i;
		} else {
			std::cout << i << '+';
		}
	}

	std::cout << '=' << result << '\n';

	return 0;
}
