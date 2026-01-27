#include <bits/stdc++.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
	int n, p, m, k, d, ans;
	std::cin >> n >> p >> m >> k >> d;
	ans = p - m - k + d - n;
	if (ans > 0) {
		std::cout << "Sad :((\n";
		ans--;
	} else {
		std::cout << "Happy :>\n";
	}

	std::cout << abs(ans) << "\n";
	return 0;
}
