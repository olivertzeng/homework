#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n;
	std::cin >> n;
	n = std::sqrt(n);
	std::cout << n << '\n';

	return 0;
}
