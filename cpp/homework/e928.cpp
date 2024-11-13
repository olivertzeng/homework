#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n;
	int usrn[n + 1];
	for (auto &num : usrn) {
		std::cin >> num;
	}
	std::cin >> m;
	int usrm[m + 1];
	for (auto &num : usrm) {
		std::cin >> num;
	}
	int ans[1000] = {0};
	for (int i = 0; i <= m + n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j <= n && i - j <= m)
				ans[i] += usrn[j] * usrm[i - j];
		}
	}
	std::cout << m + n << '\n';
	for (int i = 0; i <= m + n; i++) {
		std::cout << ans[i] << (i == m + n ? "\n" : " ");
	}

	return 0;
}
