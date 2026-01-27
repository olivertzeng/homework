#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int usr;
	while (std::cin >> usr) {
		bool result = (!(usr % 4) && usr % 100 || !(usr % 400));
		std::cout << (result ? "a leap year\n" : "a normal year\n");
	}

	return 0;
}
