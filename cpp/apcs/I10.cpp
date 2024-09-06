#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, record = 0, tmp = 0;
	std::cin >> n;
	std::vector<long> visited(n);
	std::map<long, long> songs;
	long k[n];
	for (int i = 0; i < n; i++) {
		std::cin >> k[i];
	}
	visited.clear();

	for (auto &song : k) {
		if (std::find(visited.begin(), visited.end(), song) == visited.end()) {
			visited.push_back(song);
			tmp++;
		} else {
			visited.clear();
			record = std::max(record, tmp);
			tmp = 1;
		}
	}
	record = std::max(record, tmp);
	std::cout << record << '\n';

	return 0;
}
