#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, ans = 0;
		std::cin >> a >> b;
		for (int j = a; j <= b; j++)
			ans += j * (sqrt(j) == floor(sqrt(j)));
		std::cout << "Case " << i + 1 << ": " << ans << '\n';
	}

	return 0;
}
