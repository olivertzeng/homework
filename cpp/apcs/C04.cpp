#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int h, w, n;
	std::cin >> h >> w >> n;
	int m[500][500] = {0};
	for (int i = 0; i < n; i++) {
		int r, c, t, x;
		std::cin >> r >> c >> t >> x;
		for (int j = 0; j < h; j++)
			for (int k = 0; k < w; k++)
				if (abs(r - j) + abs(c - k) <= t)
					m[j][k] += x;
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			std::cout << m[i][j] << (j + 1 == w ? "\n" : " ");

	return 0;
}
