// BUG: Not working
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string usr;
	std::stack<char> ref;
	std::cin >> usr;

	for (int i = 0, n = usr.size(); i < n; i++) {
		if (i <= n / 2 - !(n % 2))
			ref.push(usr[i]);
		else if (i == n / 2 && n % 2 || ref.top() == usr[i])
			ref.pop();
		else {
			bool found = false;
			for (int j = i + 1; j < n; j++) {
				if (usr[j] == ref.top()) {
					std::swap(usr[i], usr[j]);
					ref.pop();
					found = true;
					break;
				}
			}
			if (!found) {
				std::cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}

	std::cout << usr << '\n';

	return 0;
}
