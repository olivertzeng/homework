#include <iostream>

int main() {
	int n, m, d;
	bool ans = false;
	std::cin >> n >> m >> d;
	if (!(d % n || d % m)) {
		ans = true;
	} else if (d > n && d > m) {
		int nmax = d / n;
		int mmax = d / m;
		for (int i = 1; i <= nmax; i++) {
			for (int j = mmax; j >= 1; j--) {
				if (n * i + m * j == d) {
					ans = true;
					break;
				}
			}
			if (ans)
				break;
		}
	}
	std::cout << (ans ? "YES\n" : "NO\n");
}
