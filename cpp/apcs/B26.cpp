#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, cap;
	std::cin >> n;
	while (n != -1) {
		std::cin >> cap;
		int d = 0, t = n * cap;
		for (int t = n * cap; n > 0 && t; d++) {
			t -= n;
			n = t / cap + 1;
		}
		std::cout << d << '\n';
		std::cin >> n;
	}

	return 0;
}
