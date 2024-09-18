// BUG: Not working

#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, ans = 0;
	long long s[(int)2e5];
	std::cin >> n >> m;
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] += s[i - 1];
	}

	for (int i = 1; i <= n; i++)
		s[i + n] = s[i] + s[n];

	while (m--) {
		long long q;
		std::cin >> q;
		ans = std::lower_bound(s + ans + 1, s + ans + n + 1, s[ans] + q) - s;
		ans %= n;
	}

	std::cout << ans << '\n';

	return 0;
}
