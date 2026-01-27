#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, goal, ans = 0;
	std::cin >> n >> goal;
	std::vector<long long> vt(n);
	int begin = 0, end = n - 1;
	for (int i = 0; i < n; i++) {
		std::cin >> vt[i];
	}

	std::sort(vt.begin(), vt.end());
	do {
		if (vt[begin] + vt[end] == goal) {
			ans++;
		} else if (vt[begin] + vt[end] < goal) {
			begin++;
		} else {
			end--;
		}
	} while (begin < end);

	std::cout << (ans ? std::to_string(ans) : "IMPOSSIBLE") << '\n';

	return 0;
}
