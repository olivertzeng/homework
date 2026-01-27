#include <iostream>

long long m, n, ans = 0;

void solve(int i = 1, int s = 0) {
	if (s + n - i > m)
		return;
	if (i == n) {
		ans += s == m;
		return;
	}
	for (long long x = 1; x <= i; x++) {
		solve(i + 1, s + x);
	}
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::cin >> n;
	long long p[n];
	for (auto &points : p) {
		std::cin >> points;
	}

	return 0;
}
