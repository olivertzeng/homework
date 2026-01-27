#include <cmath>
#include <ios>
#include <iostream>

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	double n;
	std::cin >> n;
	std::cout << std::round(std::sqrt(n) * pow(10, 5)) / pow(10, 5) << '\n';

	return 0;
}
