#include <bits/stdc++.h>

int n, stars, t, u;
int main(int argc, char *argv[]) {
	std::cin >> stars;
	while (stars--) {
		std::cin >> n;
		for (int i = 0; i < (2 * n - 3); i++) {
			// the number of spaces
			t = abs(n - i - 2) + 1;
			if (t == 2) {
				t = 0;
			}
			// the number of stars
			u = 2 * (n - t);
			while (t--) {
				std::cout << " ";
			}
			while (--u) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}
	return 0;
}
