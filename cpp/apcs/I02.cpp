#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, k, num;
	std::cin >> n >> k;
	long long left = 0, right = n - 1;
	std::vector<std::pair<long long, long long>> usr(n);
	for (long long i = 0; i < n; i++) {
		std::cin >> num;
		usr[i] = {num, i + 1};
	}

	std::sort(usr.begin(), usr.end());

	while (left < right) {
		long long sum = usr[left].first + usr[right].first;
		if (sum == k) {
			std::cout << usr[right].second << ' ' << usr[left].second << '\n';
			return 0;
		} else if (sum > k)
			right--;
		else
			left++;
	}

	std::cout << "IMPOSSIBLE";

	return 0;
}
