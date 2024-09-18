#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::vector<bool> usr = {false};
	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int node;
		std::cin >> node;
		usr[node] = true;
	}
	while (std::binary_search(usr.begin(), usr.end(), false)) {
	}

	return 0;
}
