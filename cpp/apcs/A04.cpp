#include <iostream>

int main(int argc, char *argv[]) {
	int a, b, c, d;
	std::cin >> a >> b;
	std::cin >> c >> d;
	std::cout << 60 * (60 * (c - a) + d - b) << '\n';

	return 0;
}
