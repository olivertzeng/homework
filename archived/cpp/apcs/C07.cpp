#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int votes[26] = {0};
	std::string usr;
	std::cin >> usr;
	for (int i = 0; i < usr.size(); i++) {
		int temp = static_cast<int>(usr[i]) - 97;
		votes[temp]++;
	}
	for (int i = 0; i < 26; i++) {
		std::cout << static_cast<char>(i + 97) << ": " << votes[i] << '\n';
	}

	return 0;
}
