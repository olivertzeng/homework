#include <iostream>
#include <numeric>

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int a, b;
	while (std::cin >> a) {
		std::cin >> b;
		std::cout << std::lcm(a, b) << '\n';
	}

	return 0;
}
