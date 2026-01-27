#include <iostream>
#include <map>
#include <stack>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::map<char, int> dora;
	dora['('] = 1;
	dora['['] = 2;
	dora['<'] = 3;
	dora['{'] = 4;
	dora[')'] = -1;
	dora[']'] = -2;
	dora['>'] = -3;
	dora['}'] = -4;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string usr;
		std::stack<char> chips;
		std::cin >> usr;
		bool ans = true;
		for (auto &var : usr) {
			if (dora[var] > 0) {
				chips.push(var);
			} else {
				if (chips.empty() || dora[var] + dora[chips.top()]) {
					ans = false;
					std::cout << "N\n";
					break;
				} else {
					chips.pop();
				}
			}
		}
		if (ans && chips.empty()) {
			std::cout << "Y\n";
		} else if (ans) {
			std::cout << "N\n";
		}
	}

	return 0;
}
