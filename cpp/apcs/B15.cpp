#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, x, y;
	std::cin >> n >> m >> x >> y;
	int xc = (y * m - n) / (y - x);
	float xcf = ((float)y * m - n) / (y - x);
	int yc = m - xc;
	if (xc == abs(xc) && yc == abs(yc) && xcf == xc)
		std::cout << xc << ' ' << yc << '\n';
	else
		std::cout << "-1 -1\n";

	return 0;
}
