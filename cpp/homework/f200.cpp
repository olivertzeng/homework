#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n;
	std::cin >> n;
	for (long long i = n; i >= 0; i--) {
		if (!i) {
			std::cout << i << '\n';
		} else {
			std::cout << i << ' ';
		}
	}

	return 0;
}
