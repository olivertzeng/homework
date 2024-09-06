#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int m;
	std::cin >> m;
	std::cout << m / 60 << ' ' << m - 60 * (m / 60) << '\n';

	return 0;
}
