#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long k, num, usr[(int)2e5];
	int n, ans = 0;
	std::cin >> n >> k;
	int left = 0, right = n - 1;
	for (long long i = 0; i < n; i++) {
		std::cin >> num;
		usr[i] = num;
	}

	std::sort(usr, usr + n);

	while (left < right) {
		long long sum = usr[left] + usr[right];
		if (sum <= k)
			left++;
		right--;
		ans++;
	}

	if (left == right) {
		ans++;
	}

	std::cout << ans << '\n';

	return 0;
}
