#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, buses[3] = {1, 1, 1};
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
		long long temp = 9223372036854775806;
		int index = 0;
		for (int i = 0; i < 3; i++) {
			if (temp > llabs(stop[var.first] - stop[buses[i]])) {
				temp = llabs(stop[var.first] - stop[buses[i]]);
				index = i;
			}
		}
		cost += std::llabs(stop[var.second] - stop[var.first]) + temp;
		buses[index] = var.second;
	}

	std::cout << cost << '\n';

	return 0;
}
