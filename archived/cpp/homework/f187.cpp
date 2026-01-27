#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::vector<int> usr(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> usr[i];
	}
	std::sort(usr.begin(), usr.end());
	std::cout << usr[0] << '\n';

	return 0;
}
