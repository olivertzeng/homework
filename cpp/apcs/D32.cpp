#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	int A[n];
	for (int i = 0; i < n; i++) {
		A[i] = i + 1;
	}
	std::vector<bool> use(n, 0);
	for (int i = 0; i < k; i++)
		use[i] = 1;
	do {
		for (int i = 0; i < n; i++)
			if (use[i])
				std::cout << A[i] << ' ';
		std::cout << '\n';
	} while (std::prev_permutation(use.begin(), use.end()));

	return 0;
}
