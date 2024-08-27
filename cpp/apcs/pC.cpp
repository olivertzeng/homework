#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	while (n--) {
		long long num;
		std::cin >> num;
		bool found = false;
		for (long long x = 1; x * x <= num; ++x) {
			if (num % x == 0) {
				long long y = num / x;
				if ((x + y) % 2 == 0 && (y - x) > 0) {
					long long a = (y - x) / 2;
					long long b = (x + y) / 2;
					std::cout << "YES" << '\n';
					std::cout << a << " " << b << '\n';
					found = true;
					break;
				}
			}
		}
		if (!found) {
			std::cout << "NO" << '\n';
		}
	}
	return 0;
}
