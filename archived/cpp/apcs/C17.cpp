#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

// BUG: I have no idea about what to do here

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, t, ans[3];
	std::cin >> n >> t;
	bool sick[n];
	std::vector<std::pair<int, std::pair<int, int>>> events(n);
	for (auto &num : sick)
		std::cin >> num;
	for (auto &num : events)
		std::cin >> num.first >> num.second.first >> num.second.second;
	std::sort(events.begin(), events.end());
	for (auto &num : events) {
		// NOTE: Something for later
	}

	return 0;
}
