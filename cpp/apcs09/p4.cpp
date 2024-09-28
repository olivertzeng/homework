#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	long long stop[1001];
	long long cost = 0;
	std::vector<std::pair<int, int>> step(n);
	for (int i = 0; i < n; i++) {
		std::cin >> step[i].first >> step[i].second;
	}

	for (int i = 1; i <= m; i++) {
		std::cin >> stop[i];
	}

	for (auto &var : step) {
		cost += std::llabs(stop[var.second] - stop[var.first]);
	}

	std::cout << cost << '\n';

	return 0;
}
