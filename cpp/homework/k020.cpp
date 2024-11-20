#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int r, w;
	std::cin >> r >> w;
	int usr[r][w];
	for (auto &sub : usr)
		for (auto &temp : sub)
			std::cin >> temp;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < r; j++)
			std::cout << usr[j][i] << (j + 1 == r ? "\n" : " ");

	return 0;
}
