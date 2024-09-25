#include <iostream>

long long dp[(long long)1e9];

long long calc(int x) {
	if (!x)
		return 0;
	if (x == 1 || x == 2) {
		return 1;
	}
	if (dp[x])
		return dp[x];
	return dp[x] = calc(x - 1) + calc(x - 2) + calc(x - 3);
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long usr;
	std::cin >> usr;
	while (usr != -1) {
		std::cout << calc(usr) << '\n';
		std::cin >> usr;
	}

	return 0;
}
