#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int votes[26] = {0};
	std::string usr;
	std::cin >> usr;
	for (int i = 0; i < usr.size(); i++) {
		char c;
		std::cin >> c;
		int temp = static_cast<int>(c) - 97;
		votes[c]++;
	}
	for (int i = 0; i < usr.size(); i++) {
		std::cout << static_cast<char>(i + 97) << ": " << votes[i] << '\n';
	}

	return 0;
}
