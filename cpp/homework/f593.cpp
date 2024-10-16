#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int con[5], usr[5], ans = 0;
	for (auto &var : con) {
		std::cin >> var;
	}
	for (auto &var : usr) {
		std::cin >> var;
	}
	std::sort(con, con + 5);
	for (auto &var : usr) {
		if (std::binary_search(con, con + 5, var)) {
			ans++;
		}
	}
	if (ans) {
		std::cout << "Wow, you match " << ans << " numbers!\n";
	} else {
		std::cout << "working hard should be a better way of making money.\n";
	}

	return 0;
}
