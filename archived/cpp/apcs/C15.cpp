#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	int v[n], p[n], a[m], ans[n], count[n - 1];
	for (auto &num : count)
		num = 0;
	for (auto &num : v)
		std::cin >> num;
	for (int i = 1; i < n; i++) {
		std::cin >> p[i];
		count[p[i]]++;
	}
	for (auto &num : a) {
		std::cin >> num;
		count[p[num]]--;
	}
	for (int i = 1; i < n; i++)
		if (std::find(a, a + m, i) == a + m)
			v[i] += v[p[i]] / count[p[i]];
	for (int i = 0; i < n; i++)
		std::cout << v[i] << (i + 1 == n ? "\n" : " ");

	return 0;
}
