#include <iostream>

double calc(double N, double M, double x, double D) { return (D - N * x) / M; }

int main() {
	double n, m, d;
	std::cin >> n >> m >> d;
	std::string ans = "NO";
	for (double i = 1; i <= 205; i++) {
		int y = calc(n, m, i, d);
		if (y % 2 == 0 && y) {
			ans = "YES";
			break;
		}
	}
	std::cout << ans << "\n";
}
