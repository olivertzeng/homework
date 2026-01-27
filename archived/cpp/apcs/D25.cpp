#include <iostream>

int dp[11][11] = {0};

int calc(int a, int b) {
	if (b == 1 || a == b)
		return 1;
	if (dp[a][b] != 0)
		return dp[a][b];
	dp[a][b] = calc(a - 1, b) + calc(a - 1, b - 1);
	return dp[a][b];
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int x, y;
	std::cin >> x >> y;
	std::cout << calc(x, y) << '\n';

	return 0;
}
