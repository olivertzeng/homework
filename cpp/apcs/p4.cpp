#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, k, ans = -1;
	std::cin >> n >> k;
	std::vector<long long> lib;
	std::vector<long long> usr(k);

	for (int i = 0; i < n; i++) {
		long long tmp;
		std::cin >> tmp;
		usr.push_back(tmp);
	}

	for (auto var : usr) {
		if (std::find(lib.begin(), lib.end(), var) == lib.end()) {
			ans++;
			lib.push_back(var);
			if (lib.size() > k) {
				lib.erase(lib.begin());
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}
