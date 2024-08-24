#include <algorithm>
#include <iostream>
#include <vector>
std::vector<std::pair<int, int>> a;
std::vector<int> pre;

int lucky(int l, int r) {
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
	pre.resize(n);

	for (int i = 0; i < n; i++) {
		long long ai;
		std::cin >> ai;
		a[i] = {ai, i};
		pre[i] = ai;
	}

	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + pre[i];
	}

	std::sort(a.begin(), a.end());
	int ans = lucky(0, n - 1);
	std::cout << a[ans].first << "\n";
	return 0;
}
