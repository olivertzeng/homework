#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, sum = 0;
	std::cin >> n;
	int cost[n];
	for (int i = 0; i < n; i++) {
		std::cin >> cost[i];
	}

	std::sort(cost, cost + n);

	for (int i = 0; i < n; i++) {
		sum += cost[i] * (n - i);
	}

	std::cout << sum << '\n';

	return 0;
}
