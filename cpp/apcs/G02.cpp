#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int>vt[n];
	for (int i = 0; i < n; i++) {
		int tmp, tmperson;
		std::cin >> tmp >> tmperson;
		vt[tmp].push_back(tmperson);
	}
	return 0;
}
