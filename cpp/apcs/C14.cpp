#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	// INFO: fc stands for flip count
	// 		 sc stands for spin count
	// BUG: Not working
	int r, c, m, opt, fc = 0, sc = 0;
	std::cin >> r >> c >> m;
	bool f = false;
	std::vector<std::vector<long long>> usr(r, std::vector<long long>(c));
	std::vector<std::vector<long long>> fusr(c, std::vector<long long>(r));
	for (auto &sub : usr)
		for (auto &num : sub)
			std::cin >> num;
	for (int i = 0; i < m + 1; i++) {
		if (i == m)
			opt = !opt;
		else
			std::cin >> opt;
		if (opt) {
			switch (sc % 4) {
			case 1:
				for (int j = 0; j < r; j++)
					for (int k = 0; k < c; k++)
						if (f)
							usr[j][c - k - 1] = fusr[k][j];
						else
							fusr[k][r - j - 1] = usr[j][k];
				f = !f;
				break;
			case 2:
				for (int j = 0; j < r / 2; j++)
					for (int k = 0; k < c; k++)
						if (f)
							std::swap(fusr[k][j], fusr[c - k - 1][r - j - 1]);
						else
							std::swap(usr[j][k], usr[r - j - 1][c - k - 1]);
				if (r % 2) {
					for (int j = 0; j < c / 2; j++) {
						if (f)
							std::swap(fusr[j][r / 2], fusr[c - j - 1][r / 2]);
						else
							std::swap(usr[r / 2][j], usr[r / 2][c - j - 1]);
					}
				}
				break;
			case 3:
				for (int j = 0; j < r; j++)
					for (int k = 0; k < c; k++)
						if (f)
							usr[r - j - 1][k] = fusr[k][j];
						else
							fusr[c - k - 1][j] = usr[j][k];
				f = !f;
				break;
			}
			fc++;
			sc = 0;

		} else {
			if (fc % 2) {
				if (f)
					for (int j = 0; j < c / 2; j++)
						std::swap(fusr[j], fusr[c - j - 1]);
				else
					for (int j = 0; j < r / 2; j++)
						std::swap(usr[j], usr[r - j - 1]);
			}
			sc++;
			fc = 0;
		}
	}
	if (f) {
		std::cout << c << ' ' << r << '\n';
		for (int i = 0; i < c; i++)
			for (int j = 0; j < r; j++)
				std::cout << fusr[i][j] << (j + 1 == r ? "\n" : " ");
	} else {
		std::cout << r << ' ' << c << '\n';
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				std::cout << usr[i][j] << (j + 1 == c ? "\n" : " ");
	}

	return 0;
}
