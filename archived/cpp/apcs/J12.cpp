#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	long long n;
	std::cin >> n;

	std::vector<long long> coins(n);
	for (long long i = 0; i < n; i++) {
		std::cin >> coins[i];
	}

	std::sort(coins.begin(), coins.end());

	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		if (coins[i] > sum + 1) {
			break;
		}
		sum += coins[i];
	}

	std::cout << sum + 1 << '\n';

	return 0;
}
