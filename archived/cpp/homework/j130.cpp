#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> usr(n);
	for (auto &num : usr) {
		std::cin >> num;
	}
	std::vector<int> usrr(usr.rbegin(), usr.rend());
	for (int i = 0; i < n; i++) {
		std::cout << usr[i] << (i + 1 == n ? "\n" : " ");
	}
	for (int i = 0; i < n; i++) {
		std::cout << usrr[i] << (i + 1 == n ? "\n" : " ");
	}
	std::cout << *std::max_element(usr.begin(), usr.end()) << '\n';
	std::cout << (n % 2 ? usr[n / 2] : usr[n / 2 - 1]) << '\n';

	return 0;
}
