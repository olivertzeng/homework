#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long usr;
	std::cin >> usr;
	for (int i = 0; i < 3; i++) {
		bool result = (!(usr % 4) && usr % 100 || !(usr % 400));
		std::cout << (result ? "yes\n" : "no\n");
		usr += 10;
	}

	return 0;
}
