#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, q, t, usr, ans = 0;
	std::cin >> n >> q >> t;
	int d[n], da[n - 1];
	d[0] = da[0] = 0;
	for (int i = 1; i < n; i++)
		std::cin >> d[i];
	for (int i = 0; i < n; i++) {
		da[i] = d[i] + da[i - 1];
	}
	for (int i = 0; i < q; i++) {
		std::cin >> usr;
		ans += abs(da[t - 1] - da[usr - 1]);
		t = usr;
	}
	std::cout << ans << '\n';

	return 0;
}
