#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> u(n + m), v(n + m);
	std::vector<std::pair<int, long long[9]>> usr(m);

	for (int i = 0; i < n + m - 1; i++) {
		std::cin >> u[i] >> v[i];
	}

	for (int i = 0; i < m; i++) {
		std::cin >> usr[i].first;
		for (int j = 0; j < 9; j++) {
			std::cin >> usr[i].second[j];
		}
	}

	std::cout << usr.back().first << '\n';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << usr.back().second[i * 3 + j]
					  << (i != 2 || j != 2 ? " " : "");
		}
		std::cout << '\n';
	}

	std::cout << '\n';

	return 0;
}
