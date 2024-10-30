#include <cstdlib>
#include <iostream>

void calc(int &a, int &b) {
	if (abs(a) >= 100)
		a /= b;
	else if (abs(a) >= 10)
		(a > 0) ? a -= b : a += b;
	else if (abs(a) >= 1)
		a *= b;
	if (!a)
		a = 10000;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n, temp;
		std::cin >> n >> temp;
		if (!n)
			n = 10000;
		while (temp) {
			calc(n, temp);
			std::cin >> temp;
		}
		std::cout << n << '\n';
	}

	return 0;
}
