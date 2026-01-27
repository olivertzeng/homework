#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, o, buf = 1;
	std::cin >> n >> m >> o;
	int usra[n][m];
	int usrb[m][o];
	int ans[101][101] = {0};

	for (auto &sub : usra)
		for (auto &temp : sub)
			std::cin >> temp;

	for (auto &sub : usrb)
		for (auto &temp : sub)
			std::cin >> temp;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < o; ++j)
			for (int k = 0; k < m; ++k)
				ans[i][j] += usra[i][k] * usrb[k][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < o; j++)
			std::cout << ans[i][j] << (j + 1 == o ? "\n" : " ");

	return 0;
}
