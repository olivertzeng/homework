#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int usr;
	int sum = 0;
	std::cin >> usr;

	while (usr > 0) {
		int num = usr % 10;
		sum += num;
		usr /= 10;
	}

	std::cout << sum << '\n';

	return 0;
}
