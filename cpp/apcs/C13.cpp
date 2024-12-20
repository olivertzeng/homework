#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, r, c;
	std::cin >> n >> m >> r >> c;
	r--;
	c--;
	int room[n][m];
	for (auto &sub : room)
		for (auto &e : sub)
			e = 0;
	std::map<int, char> dict = {{0, 'X'}, {1, 'O'}, {2, 'V'}};
	for (auto &e : room[r])
		e++;
	for (int i = 0; i < n; ++i)
		room[i][c]++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (abs(i - r) <= 1 && abs(j - c) <= 1 && (i != r || j != c))
				room[i][j]++;
	for (auto &sub : room)
		for (auto &e : sub)
			e %= 2;
	room[r][c] = 2;

	for (auto &sub : room) {
		for (auto &e : sub)
			std::cout << dict[e];
		std::cout << '\n';
	}
	return 0;
}
