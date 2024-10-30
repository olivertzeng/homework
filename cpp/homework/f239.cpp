#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> usr(n);
	for (auto &num : usr) {
		std::cin >> num;
	}
	std::sort(usr.begin(), usr.end());
	std::cout << usr.back() - usr[0] << '\n';

	return 0;
}
