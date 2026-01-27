#include <iostream>

long long dp[(int)2e5] = {0};

long long calc(int x) {
	if (x > 100)
		return x - 10;
	if (dp[x])
		return dp[x];
	dp[x] = calc(calc(x + 11));
	return dp[x];
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	while (n) {
		std::cout << "f91(" << n << ") = " << calc(n) << '\n';
		std::cin >> n;
	}
	return 0;
}
