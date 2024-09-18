#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int usr[10], h;
	for (auto &var : usr) {
		std::cin >> var;
	}
	std::cin >> h;
	std::sort(usr, usr + 10);
	std::cout << std::upper_bound(usr, usr + 10, h + 30) - usr << '\n';

	return 0;
}
