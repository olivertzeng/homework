#include <cmath>
#include <iostream>
#include <utility>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	double record = INFINITY, temp;
	std::pair<int, int> ans, usr;
	std::cin >> usr.first >> usr.second >> n;
	std::pair<int, int> coord[n];
	for (auto &p : coord) {
		std::cin >> p.first >> p.second;
	}
	for (int i = 0; i < n; i++) {
		temp = std::pow(usr.first - coord[i].first, 2) +
			   std::pow(usr.second - coord[i].second, 2);
		if (temp < record) {
			record = temp;
			ans = {coord[i].first, coord[i].second};
		}
	}
	std::cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}
