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
		if (i < n / 2)
			ref.push(usr[i]);
		else if (ref.top() != usr[i]) {
			if (!(i == n / 2 && n % 2)) {
				for (int j = i + 1; j < n; j++) {
					if (usr[j] == ref.top()) {
						std::swap(usr[i], usr[j]);
						break;
					} else if (j >= n - 1) {
						std::cout << "IMPOSSIBLE\n";
						return 0;
					}
				}
			}
		} else
			ref.pop();
	}

	std::cout << usr << '\n';

	return 0;
}
