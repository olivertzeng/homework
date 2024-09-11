#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	n++;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			std::cout << '_';
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			std::cout << i;
		}
		std::cout << '\n';
	}
	return 0;
}
