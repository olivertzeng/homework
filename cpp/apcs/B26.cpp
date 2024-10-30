#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, cap;
	std::cin >> n;
	while (n != -1) {
		std::cin >> cap;
		int d = 0, t = n * cap;
		while (n > 1 && t > 0) {
			t -= n;
			n = t / cap + 1;
			d += 1;
		}
		d += t;
		std::cout << d << '\n';
		std::cin >> n;
	}

	return 0;
}
