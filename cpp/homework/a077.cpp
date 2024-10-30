#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	double record = 0, temp;
	std::cin >> n;
	std::pair<int, int> coord[n];
	std::pair<int, int> ans;
	for (auto &p : coord) {
		std::cin >> p.first >> p.second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = std::pow(coord[i].first - coord[j].first, 2) +
				   std::pow(coord[i].second - coord[j].second, 2);
			if (temp > record) {
				record = temp;
				ans = {std::min(i, j), std::max(i, j)};
			}
		}
	}
	std::cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}
