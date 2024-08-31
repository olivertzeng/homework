#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	srand(time(NULL));
	int ans = rand() % 100 + 1;
	int usr;
	while (std::cin >> usr) {
		if (usr == ans) {
			std::cout << "Congrats\n";
			break;
		} else if (usr < ans) {
			std::cout << "Please guess a greater number\n";
		} else {
			std::cout << "Please guess a smaller number\n";
		}
	}
	return 0;
}
