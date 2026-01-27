#include <iostream>

int dp[40] = {0};

int calc(int x, int &c) {
	c++;
	dp[0] = 0;
	dp[1] = 1;
	if (x <= 1)
		return x;
	dp[x] = calc(x - 1, c) + calc(x - 2, c);
	return dp[x];
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, c = 0;
	std::cin >> n;
	std::cout << calc(n, c) << ' ' << c << '\n';

	return 0;
}
