#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> fr(n);
	for (int i = 0; i < k; i++) {
		int a, b;
		std::cin >> a >> b;
		fr[a - 1].push(b);
		fr[b - 1].push(a);
	}
	for (auto &pq : fr) {
		while (!pq.empty()) {
			int temp = pq.top();
			pq.pop();
			std::cout << temp << (pq.empty() ? "\n" : " ");
		}
	}

	return 0;
}
