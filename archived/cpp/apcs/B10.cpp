#include <algorithm>
#include <iostream>
#include <utility>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int x[4], y[4];
	std::pair<int, int> usr;

	for (int i = 0; i < 4; i++) {
		std::cin >> x[i] >> y[i];
	}

	std::sort(x, x + 4);
	std::sort(y, y + 4);

	std::cin >> usr.first >> usr.second;

	if (x[0] <= usr.first && usr.first <= x[3] && y[0] <= usr.second &&
		usr.second <= y[3]) {
		std::cout << "IN\n";
	} else {
		std::cout << "OUT\n";
	}

	return 0;
}
