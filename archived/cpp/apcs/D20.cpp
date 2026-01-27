#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	long long a[n];
	for (auto &e : a)
		std::cin >> e;
	std::sort(a, a + n);
	for (int i = 0; i < n; i++)
		std::cout << a[i] << (i + 1 == n ? "\n" : " ");

	return 0;
}
