#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long double n, usr, sum = 0;
	std::cin >> n;
	for (long double i = 0; i < n; i++) {
		std::cin >> usr;
		sum += usr;
	}
	std::cout << std::fixed << std::setprecision(3) << sum / n << '\n';

	return 0;
}
