#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n;
	std::cin >> n;
	for (long long i = 0; i < n; i++) {
		std::cout << "I love you.\n";
	}

	return 0;
}
