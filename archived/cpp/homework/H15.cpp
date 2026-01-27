#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, c = 0;
	std::cin >> n;
	int fr[n];
	bool searched[n];
	for (auto &person : fr)
		std::cin >> person;

	for (int i = 0; i < n; i++) {
		if (!searched[i]) {
			int ad = i;
			while (fr[ad] != i) {
				searched[ad] = true;
				ad = fr[ad];
			}
			searched[ad] = true;
			c++;
		}
	}
	std::cout << c << '\n';

	return 0;
}
