#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int h, m;
	std::cin >> h >> m;
	std::cout << h * 60 + m;

	return 0;
}
