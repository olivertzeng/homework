#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long usr[6];
	for (auto &num : usr) {
		std::cin >> num;
	}
	long long tmp;
	while (std::cin >> tmp && tmp != -1) {
		std::sort(usr, usr + 6);
		if (std::binary_search(usr, usr + 6, tmp)) {
			std::cout << "congratulations\n";
		} else {
			std::cout << "miss it\n";
		}
	}
	return 0;
}
