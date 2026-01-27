#include <algorithm>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int k, w, s, e, sum = 20;
	std::cin >> k >> w >> s >> e;
	sum += 5 * std::floor((float)w / 2);
	if (e > 18) {
		for (int i = std::max(s, 18); i < e; i++) {
			sum += 10 * i + 5;
		}
	}
	sum += (k > 2 ? 5 : 0) * (k - 2);
	std::cout << sum << '\n';

	return 0;
}
