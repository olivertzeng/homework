#include <algorithm>
#include <iostream>
#include <utility>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::pair<int, int> cord[1005];
	for (int i = 0; i < n; i++) {
		std::cin >> cord[i].first >> cord[i].second;
	}
	std::sort(cord, cord + n);
	for (int i = 0; i < n; i++) {
		std::cout << cord[i].first << " " << cord[i].second << '\n';
	}

	return 0;
}
