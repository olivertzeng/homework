#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++)
		std::cin >> n;
	std::cout << "Chung Chung 0rz !!!\n";

	return 0;
}
