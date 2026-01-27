#include <cmath>
#include <iostream>

// INFO: 0 => right x++
// 		 1 => down y++
// 		 2 => left x--
// 		 3 => up y--
int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t, n;
	std::cin >> n;
	int x = 0, y = 0, o = 0, length = n, ans[n][n], test = 1, time = 0;

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
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			std::cout << ans[j][k] << (k + 1 == n ? "\n" : " ");

	return 0;
}
