#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, t;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		int ad =
			!(t % 6)			 ? 1
			: (t % 3) && (t % 2) ? 2
			: ((t % 7) && !(t % 2)) || (std::floor(std::sqrt(t)) == sqrt(t))
				? 3
				: 0;
		std::cout << ad << (i + 1 == n ? "\n" : " ");
	}

	return 0;
}
