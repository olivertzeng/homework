#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int m, n, ant = 0, grasshopper = 0, temp;
	std::cin >> m >> n;
	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		ant += temp;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		grasshopper += temp;
	}
	std::cout << (ant > grasshopper && m > n ? "Yes\n" : "No\n");

	return 0;
}
