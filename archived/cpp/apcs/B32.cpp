#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, l = 0, r = 0;
	std::cin >> n;
	std::pair<int, int> usr[n];
	for (auto &bruh : usr)
		std::cin >> bruh.second >> bruh.first;
	std::sort(usr, usr + n, std::less<>());
	for (const auto &p : usr) {
		if (p.first == -1) {
			l++;
		} else if (p.first == usr[n - 1].first) {
			r++;
		}
	}
	int total = usr[n - 1].first - n - 2 * l;
	std::cout << (total > 0 ? total : 0) << ' ' << usr[n - r].second << '\n';

	return 0;
}
