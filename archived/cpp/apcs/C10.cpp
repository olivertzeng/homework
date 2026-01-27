#include <bitset>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::bitset<3> ans;
	// NOTE: ans(0) == same
	// 		 ans(1) == increasing
	// 		 ans(2) == decreasing
	ans.set();
	std::cin >> n;
	std::vector<long long> usr(n);
	for (auto &num : usr)
		std::cin >> num;
	for (int i = 0; i < n - 1; i++) {
		if (usr[i] < usr[i + 1])
			ans[0] = ans[2] = 0;
		else if (usr[i] > usr[i + 1])
			ans[0] = ans[1] = 0;
		if (ans.none())
			break;
	}

	if (ans.none())
		std::cout << "NO\n";
	else if (ans[0])
		std::cout << "SAME\n";
	else if (ans[1])
		std::cout << "INCREASING\n";
	else
		std::cout << "DECREASING\n";

	return 0;
}
