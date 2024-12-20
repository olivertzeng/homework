#include <iostream>
#include <set>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	int kids[n][n];
	for (auto &sub : kids)
		for (auto &num : sub)
			std::cin >> num;
	for (int i = 0; i < q; i++) {
		int k, ans = 0;
		std::set<int> qu;
		std::cin >> k;
		for (int j = 0; j < k; j++) {
			int usr;
			std::cin >> usr;
			qu.insert(usr);
		}
		for (auto &e : qu)
			for (auto &f : qu)
				ans += kids[e - 1][f - 1];
		std::cout << ans << '\n';
		qu.clear();
	}

	return 0;
}
