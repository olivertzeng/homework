#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	int people[n];
	std::vector<int> ans;
	for (auto &num : people) {
		num = 1;
	}
	people[0] = 0;
	for (int i = 0; i < m; i++) {
		int temp;
		std::cin >> temp;
		people[temp] = 0;
	}
	for (int i = 1; i < n + 1; i++) {
		if (people[i]) {
			ans.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == ans.back()) {
			std::cout << ans[i] << '\n';
			break;
		} else {
			std::cout << ans[i] << ' ';
		}
	}

	return 0;
}
