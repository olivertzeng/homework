#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n;
	std::cin >> n;
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= i; j++) {
			std::cout << i;
		}
		std::cout << '\n';
	}
	return 0;
}
