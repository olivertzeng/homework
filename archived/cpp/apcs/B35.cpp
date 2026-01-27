#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int k;
	while (std::cin >> k) {
		int num, sum = 0;
		for (int i = 0; i < k; i++) {
			std::cin >> num;
			sum += num;
		}
		std::cout << (sum > k * 59 ? "no\n" : "yes\n");
	}

	return 0;
}
