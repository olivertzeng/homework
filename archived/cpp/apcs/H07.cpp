#include <algorithm>
#include <bits/stdc++.h>
#define pi std::pair<int, int>
#define f first
#define s second

std::vector<pi> vt;

/**
 * @brief: brief
 *
 * @param: pi a
 *       : pi b
 *
 * @return: bool
 */
bool cmp(pi a, pi b) {
	return pow(a.f, 2) + pow(a.s, 2) > pow(b.f, 2) + pow(b.s, 2);
}

int main(int argc, char *argv[]) {
	int n, x, y;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		vt.push_back({x, y});
	}
	std::sort(vt.begin(), vt.end(), cmp);
	std::cout << vt[1].f << ' ' << vt[1].s << '\n';
	return 0;
}
