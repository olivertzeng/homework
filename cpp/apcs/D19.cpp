#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	int a[n];
	std::vector<int> cmp;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		for (int j = 0; j < i; j++)
			cmp.push_back(a[j] - a[i]);
	}
	std::sort(cmp.begin(), cmp.end());
	std::cout << cmp[cmp.size() - 1] << '\n';

	return 0;
}
