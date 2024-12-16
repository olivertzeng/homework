#include <iostream>
#include <numeric>

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long a, b;
	std::cin >> a >> b;
	std::cout << std::gcd(a, b) << '\n';

	return 0;
}
