#include <iostream>
const long long MAX = (long long)1e7;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, ans;
	bool found = false;
	std::cin >> n;
	long long usr[n], pre[n];
	for (long long i = 0; i < n; i++) {
		std::cin >> usr[i];
	}
	for (long long i = 0; i < n; i++) {
		if (usr[i] == i) {
			ans = i;
			found = true;
		}
	}
	if (!found) {
		pre[0] = usr[0];
		for (long long i = 0; i < n; i++) {
			pre[i + 1] = pre[i] + usr[i + 1];
		}
		long long min = usr[0], index = 0;
		for (long long i = 0; i < n; i++) {
			if (usr[i] < min) {
				index = i;
				min = usr[i];
			}
		}
	}
	std::cout << ans << "\n";

	return 0;
}
