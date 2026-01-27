#include <algorithm>
#include <iostream>
#include <vector>
std::vector<std::pair<long long, long long>> a, b;
std::vector<long long> pre;

long long lucky(long long l, long long r) {
	if (l == r)
		return l;
	for (auto &[var, index] : a) {
		if (index >= l && index <= r) {
			if (index == r)
				return lucky(l, index - 1);
			long long left = pre[index - 1] - (l > 0 ? pre[l - 1] : 0);
			long long right = pre[r] - pre[index];
			if (left > right) {
				return lucky(l, index - 1);
			} else {
				return lucky(index + 1, r);
			}
		}
	}
	return l;
}

int main() {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n;
	std::cin >> n;
	a.resize(n);
	b.resize(n);
	pre.resize(n);

	for (long long i = 0; i < n; i++) {
		long long ai;
		std::cin >> ai;
		a[i] = {ai, i};
		pre[i] = ai;
	}

	for (long long i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + pre[i];
	}

	b = a;
	std::sort(a.begin(), a.end());
	long long ans = lucky(0, n - 1);
	std::cout << a[ans].first << " " << ans << "\n";
	return 0;
}
