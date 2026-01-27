#include <bits/stdc++.h>
#include <utility>

int main(int argc, char *argv[]) {
	int a, b, c;
	std::cin >> a >> b >> c;
	if (a == 0) {
		std::cout << "No real root\n";
		return 0;
	}
	int D = b * b - 4 * a * c;
	if (D < 0)
		std::cout << "No real root\n";
	else if (!D)
		std::cout << "Two same roots x=" << -b / (2 * a);
	else {
		int k = sqrt(D);
		int r1 = (k - b) / (2 * a), r2 = (-b - k) / (2 * a);
		if (r1 < r2)
			std::swap(r1, r2);
		std::cout << "Two different roots x1" << r1 << " , x2=" << r2;
	}
}
