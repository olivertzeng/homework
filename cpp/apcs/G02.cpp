#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> vt[n + 1];
	for (int i = 0; i < m; i++) {
		int tmp, tmperson;
		std::cin >> tmperson >> tmp;
		vt[tmp].push_back(tmperson);
	}
	for (int i = 0; i < q; i++) {
		int num;
		std::cin >> num;
		if (vt[num].empty()) {
			std::cout << "\n";
		} else {
			for (auto &var : vt[num]) {
				std::cout << var << " ";
			}
			std::cout << "\n";
		}
	}
	return 0;
}
