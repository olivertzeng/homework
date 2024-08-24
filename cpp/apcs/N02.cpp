#include <cstdlib>
#include <iostream>
const int MAX = 300000;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int left, n, right, usr[MAX] = {0}, L, R;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 2; i++) {
			std::cin >> left >> right;
			usr[left]++;
			usr[right + 1]--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (usr[i] > 0) {
			L = i;
		} else if (usr[i] < 0) {
			R = i;
		}
	}
	std::cout << abs(R - L) * usr[L] << '\n';

	return 0;
}
