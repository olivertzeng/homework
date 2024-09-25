#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);

	long long x;
	std::cin >> x;
	std::cout << std::abs(x) << '\n';

	return 0;
}
