#include <cstdlib>
#include <iostream>
const int MAX = 300000;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int L, R, left, n, pre[MAX] = {0}, result = 0, right, usr[MAX] = {0};
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> left >> right;
		usr[left]++;
		usr[right]--;
	}

	pre[0] = usr[0];
	for (int i = 0; i < MAX; i++) {
		pre[i + 1] = pre[i] + usr[i + 1];
	}

	for (int i = 0; i < MAX; i++) {
		if (pre[i] > 0)
			result++;
	}

	std::cout << result << '\n';
	return 0;
}
