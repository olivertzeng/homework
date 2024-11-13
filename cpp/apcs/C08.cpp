#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, buf = 0;
	std::stack<int> usr;
	std::vector<int> ans;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int u;
		std::cin >> u;
		usr.push(u);
	}
	while (!usr.empty()) {
		if (buf > usr.top())
			buf++;
		else
			buf = usr.top();
		usr.pop();
		ans.push_back(buf);
	}
	for (int i = n - 1; i >= 0; i--) {
		std::cout << ans[i] << (i ? " " : "\n");
	}

	return 0;
}
