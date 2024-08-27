#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N, X;
		std::cin >> N >> X;

		int count = 0;
		int n = N;
		while (n > 0) {
			n /= 5;
			count += n;
		}

		if (count >= X) {
			std::cout << 0 << '\n';
		} else {
			long long result = 1;
			for (int j = 2; j <= N; j++) {
				result = (result * j) % (long long)pow(10, X);
			}
			std::cout << result << '\n';
		}
	}

	return 0;
}
