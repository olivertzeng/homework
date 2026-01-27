#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int m, a, buf;
	std::cin >> m >> a;
	for (int i = 0; i < m; i++) {
		std::cin >> buf;
		if (buf >= a)
			break;
		a += buf;
	}
	std::cout << a << '\n';

	return 0;
}
