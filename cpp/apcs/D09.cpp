#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::pmr::vector<long long> usr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> usr[i];
	}
	std::cout << std::accumulate(usr.begin(), usr.end(), 0LL) << '\n';

	return 0;
}
