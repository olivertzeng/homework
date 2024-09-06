#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::cout << ((n % 2) ? "ODD\n" : "EVEN\n");

	return 0;
}
