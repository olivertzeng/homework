#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	char usr[8][8];
	for (int i = 0; i < 8; i++) {
		std::cin >> usr[i];
	}

	return 0;
}
