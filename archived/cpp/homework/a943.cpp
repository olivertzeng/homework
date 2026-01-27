#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			if (i == 7 && j == 7) {
				std::cout << i << '*' << j << '=' << i * j;
			} else {
				std::cout << i << '*' << j << '=' << i * j << '\t';
			}
		}
		std::cout << '\n';
	}

	return 0;
}
