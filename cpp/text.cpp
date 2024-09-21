#include <iostream>
#include <stack>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string usr;
	bool ans = true;
	std::stack<char> ref;
	std::cin >> usr;
	for (int i = 0; i < usr.length(); i++) {
		if (i < usr.length() / 2)
			usr.push_back(usr[i]);
		else {
			if (ref.top() == usr[i] ||
				(i == usr.length() / 2 && usr.length() % 2 == 1)) {
				ans = false;
				break;
			} else {
				ref.pop();
			}
		}
	}
	std::cout << ans;

	return 0;
}
