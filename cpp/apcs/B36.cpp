#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	long long sum = 0, k;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> k;
		sum += k * i;
	}
	std::cout << sum << '\n';

	return 0;
}
