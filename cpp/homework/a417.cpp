#include <cmath>
#include <iostream>
#include <vector>

// INFO: 0 => right
// 		 1 => down
// 		 1 => left
// 		 3 => up
int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t, n, m, o;
	std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
	for (int i = 0; i < t; i++) {
		// ans[y][x]
		int x = 0, y = 0;
		std::cin >> n >> m;
		if (m == 1) {
			o = 0;
			for (int j = 1; j <= pow(n, 2); j++) {
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
			}
		} else {
			o = 1;
		}
	}

	return 0;
}
