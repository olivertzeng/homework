#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	long long n;
	std::cin >> n;
	std::vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long long sum = a[0], maxSum = a[0];
	for (int i = 1; i < n; i++) {
		sum = std::max(a[i], sum + a[i]);
		maxSum = std::max(maxSum, sum);
	}
	std::cout << maxSum << "\n";
	return 0;
}
