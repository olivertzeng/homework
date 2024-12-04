#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> usr(n);
	for (auto &num : usr)
		std::cin >> num;
	std::vector<int> same(n, usr.back());
	std::vector<int> temp = usr;
	if (same == usr) {
		std::cout << "SAME\n";
		return 0;
	}
	std::sort(temp.begin(), temp.end());

	if (temp == usr) {
		std::cout << "INCREASING\n";
		return 0;
	}
	std::sort(temp.begin(), temp.end(), std::greater<>());
	if (temp == usr)
		std::cout << "DECREASING\n";
	else
		std::cout << "NO\n";

	return 0;
}
