#include <iostream>
#include <numeric>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	while (std::cin >> n && n) {
		long long a = 1, b;
		for (int i = 0; i < n; i++) {
			std::cin >> b;
			a = (a * b) / std::gcd(a, b);
		}
		std::cout << a << '\n';
	}

	return 0;
}
