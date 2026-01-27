#include <cstdlib>
#include <iostream>

void wave(int n) {
	for (int i = 1; i < n * 2; i++) {
		int num = n - abs(n - i);
		for (int j = 1; j <= num; j++) {
			std::cout << num;
		}
		std::cout << '\n';
	}
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		int a, f;
		std::cin >> a >> f;
		for (int j = 0; j < f; j++) {
			wave(a);
			if (j - f + 1 || i - k + 1)
				std::cout << '\n';
		}
	}

	return 0;
}
