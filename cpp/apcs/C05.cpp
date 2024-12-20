#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	int minefield[n][m], sminefield[500][500] = {0};
	// HACK: foreach syntax with 2d array

	for (auto &sub : minefield)
		for (auto &mines : sub)
			std::cin >> mines;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				for (int l = 0; l < m; l++)
					if (abs(i - k) <= 1 && abs(j - l) <= 1 &&
						(i != k || j != l))
						sminefield[i][j] += minefield[k][l];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cout << sminefield[i][j] << (j + 1 == m ? "\n" : " ");

	return 0;
}
