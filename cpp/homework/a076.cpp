#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n;
	std::vector<int> collection(41);
	while (n) {
		collection.assign(41, 0);
		for (int i = 0; i < n; i++) {
			std::cin >> m;
			for (int j = 0; j < m; j++) {
				int temp;
				std::cin >> temp;
				collection[temp - 1]++;
			}
		}
		std::sort(collection.begin(), collection.end(), std::less<int>());
		std::cout << collection[0] << '\n';
	}

	return 0;
}
