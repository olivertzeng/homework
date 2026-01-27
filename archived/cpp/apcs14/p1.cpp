#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	int usr[n];
	for (auto &num : usr)
		std::cin >> num;
	std::cout << 0 << '\n';
	return 0;
}
