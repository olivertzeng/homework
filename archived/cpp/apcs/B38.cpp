#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t;
	std::cin >> t;
	std::string d[4] = {"Pen", "Pineapple", "Apple", "Pineapple pen"};
	for (int i = 0; i < t; i++) {
		int n, j = 1, bruh = 0;
		std::cin >> n;
		for (; bruh < n; j++) {
			bruh = 2 * j * (j + 1);
		}
		j--;
		bruh = 2 * j * (j - 1);
		std::cout << d[(n - bruh - 1) / j] << '\n';
	}
	return 0;
}
