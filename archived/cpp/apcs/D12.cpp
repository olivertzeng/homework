#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::vector<int> usr(10);
	std::cout << "Lumberjacks:\n";
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (auto &num : usr)
			std::cin >> num;
		std::vector<int> g = usr, l = usr;
		std::sort(l.begin(), l.end());
		std::sort(g.begin(), g.end(), std::greater<>());
		std::cout << (usr == g || usr == l ? "Ordered\n" : "Unordered\n");
	}

	return 0;
}
