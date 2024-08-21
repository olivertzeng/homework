#include <bits/stdc++.h>
const int MAX = 2e5 + 10;

std::vector<int> graph[MAX];

signed main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	int q;
	std::cin >> q;
	while (q--) {
		int v;
		std::cin >> v;
		for (auto u : graph[v]) {
			std::cout << u << " ";
		}
		std::cout << "\n";
	}
}
