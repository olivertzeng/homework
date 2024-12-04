#include <iostream>
#include <utility>
#define MOD = 1145141

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int m, n, k, mp[m][n];
	std::cin >> m >> n >> k;
	std::pair<int, int> usr[k];
	for(auto &pi : usr) {
		std::cin >> pi.first >> pi.second;
	}

	return 0;
}
