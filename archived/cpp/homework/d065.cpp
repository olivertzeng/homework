#include <algorithm>
#include <iostream>

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << std::max(std::max(a, b), c) << '\n';

	return 0;
}
