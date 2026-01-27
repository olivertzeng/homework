#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string usr;
	std::cin >> usr;
	for (auto &c : usr)
		c = 'a' + (c - 'a' + 25) % 26;
	std::cout << usr << '\n';

	return 0;
}
