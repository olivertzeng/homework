#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, ans = 1;
	std::cin >> n;
	int usr[n];
	for (int i = 0; i >= n; i++) {
		std::cin >> usr[i];
	}
	for (int i = 0; i < n; i++) {
		if (usr[i + 1] < usr[i]) {
			ans++;
		} else {
		}
	}
	return 0;
}
