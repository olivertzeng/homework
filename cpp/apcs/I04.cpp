// BUG: Not working
#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, k, num, ans = 0;
	std::cin >> n >> k;
	long long left = 0, right = n - 1;
	std::vector<long long> usr(n);
	long long pre[200000] = {0};

	for (long long i = 0; i < n; i++) {
		std::cin >> num;
		usr[i] = num;
	}

	std::sort(usr.begin(), usr.end());

	for (long long i = 0; i < n; i++) {
		long long loc = 0;
		for (long long j = 0; j < i; j++) {
			loc += usr[j];
		}
		pre[i] = loc;
	}

	while (left < right) {
		long long sum = pre[right] - pre[left];
		if (sum == k) {
			left++;
			ans++;
		} else if (sum > k)
			right--;
		else
			left++;
	}

	std::cout << ans << '\n';

	return 0;
}
