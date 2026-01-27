#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, psum = 0, b, nmax = 0;
	std::cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		std::cin >> b;
		psum += b;
		nmax = std::max(nmax, b);
	}
	std::cout << std::max(nmax * 2, psum) << "\n";
	return 0;
}
