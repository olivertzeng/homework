#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t, usr;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int c = 0;
		std::cin >> usr;
		for (int i = 1; i <= usr; i++)
			for (int j = i + 1; j <= usr; j++)
				for (int k = j + 1; k <= usr; k++)
					if (i + j > k && i + k > j && j + k > i)
						c++;
		std::cout << c << '\n';
	}
	return 0;
}
