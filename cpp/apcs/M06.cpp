#include <iostream>

long long dp[(long long)1e5 + 5] = {0};

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	int ways[k];
	for (auto &var : ways) {
		std::cin >> var;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (auto &var : ways) {
			if (i >= var && dp[i - var]) {
				dp[i] += dp[i - var];
				dp[i] %= 998244353;
			}
		}
	}
	std::cout << dp[n] << '\n';

	return 0;
}
