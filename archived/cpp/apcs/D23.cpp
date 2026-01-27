#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	int usr[n];
	std::vector<int> ans;
	for (auto &e : usr)
		std::cin >> e;
	std::sort(usr, usr + n);
	for (int i = 0; i < n; i++)
		std::cout << usr[i] << (i + 1 == n ? "\n" : " ");
	std::set<int, std::greater<>> sec;
	for (auto &e : usr)
		sec.emplace(e);
	for (auto &e : sec)
		ans.push_back(e);
	for (int i = 0; i < ans.size(); i++)
		std::cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");

	return 0;
}
