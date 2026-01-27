#include <iostream>

int dp[200] = {0};

int fact(int x) {
	if (x <= 1)
		return 1;
	if (dp[x])
		return dp[x];
	dp[x] = x * fact(x - 1);
	return dp[x];
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::cout << fact(n) << '\n';

	return 0;
}
