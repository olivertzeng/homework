#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	int sky = n - 200 * (n / 2000);
	int kiki = n - 100 * (n / 1000);
	if (sky > kiki) {
		std::cout << kiki << ' ' << 1 << '\n';
	} else {
		std::cout << sky << ' ' << 0 << '\n';
	}

	return 0;
}
