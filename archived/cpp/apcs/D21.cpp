#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<long long> usr(n);
	for (auto &e : usr)
		std::cin >> e;
	std::sort(usr.begin(), usr.end());
	if (n % 2)
		std::cout << usr[(n + 1) / 2 - 1] << '\n';
	else
		std::cout << (usr[n / 2] + usr[n / 2 - 1]) / 2 << '\n';

	return 0;
}
