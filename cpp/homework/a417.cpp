#include <cmath>
#include <iomanip>
#include <iostream>

// INFO: 0 => right
// 		 1 => down
// 		 1 => left
// 		 3 => up
int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t, n, m, o, test = 1, time = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		// ans[y][x]
		std::cin >> n >> m;
		int x = 0, y = 0, o = (m == 2), length = n, ans[n][n];

		for (int j = 1; j <= pow(n, 2); j++) {
			test++;
			ans[y][x] = j;
			switch (o) {
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
			}
			if (test == length) {
				o++;
				o %= 4;
				time++;
				test = 1;
				if ((time == 3 && length == n) || (time == 2 && length != n)) {
					length--;
					time = 0;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			std::cout << ans[j][0];
			for (int k = 0; k < n; k++)
				std::cout << std::setw(5) << ans[j][k];
			std::cout << '\n';
		}
	}

	return 0;
}
