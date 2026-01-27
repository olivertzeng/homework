#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long l[3];
	for (auto &var : l) {
		std::cin >> var;
	}
	std::sort(l, l + 3);
	std::cout << l[2] - l[0] << '\n';

	return 0;
}
