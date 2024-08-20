#include <algorithm>
#include <iostream>

int a[200005];
int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, i = 0, x, reward = 0;
	std::sort(a, a + n);
	for (i = 0; i < n; i++)
		reward -= (n - i) * a[i];
	std::cout << reward;
	return 0;
}
