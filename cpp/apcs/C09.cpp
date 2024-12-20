#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string s;
	int usr[26] = {0};
	std::vector<char> ans;
	char mid = ' ';
	std::cin >> s;
	for (auto &c : s) {
		usr[(int)c - (int)'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (usr[i] % 2) {
			if (mid != ' ') {
				std::cout << "IMPOSSIBLE\n";
				return 0;
			}
			mid = (char)(i + (int)'A');
			usr[i]--;
		}
		for (int j = 0; j < usr[i] / 2; j++)
			ans.push_back((char)(i + (int)'A'));
	}

	std::vector<char> rans(ans.rbegin(), ans.rend());
	for (auto &c : ans)
		std::cout << c;
	if (mid != ' ')
		std::cout << mid;
	for (auto &c : rans)
		std::cout << c;
	std::cout << '\n';

	return 0;
}
