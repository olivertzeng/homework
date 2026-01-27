#include <iostream>

const long long MOD = (long long)1e9;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b, ans;
		std::cin >> a >> b;
		if (a && b) {
			a %= MOD;
			b %= MOD;
			long long ans = a * b;
			ans %= MOD;
			std::cout << ans << '\n';
		} else {
			std::cout << 0 << '\n';
		}
	}

	return 0;
}
