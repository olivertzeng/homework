#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	int c1, c2, v1, v2;
	std::cin >> c1 >> c2 >> v1 >> v2;
	if (c1 * v1 * 2 == c2 * v2 * 5) {
		std::cout << "Yes\n" << c1 * v1 * 2 << "\n";
	} else {
		std::cout << "No\n";
	}
	return 0;
}
