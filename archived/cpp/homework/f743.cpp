#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	while (std::cin >> n)
		std::cout << (long long)(std::pow(2, n) - 1) << '\n';

	return 0;
}
