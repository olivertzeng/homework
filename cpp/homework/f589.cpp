#include <iostream>
#include <stack>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::stack<long long> usr;
	for (int i = 0; i < 10; i++) {
		int num;
		std::cin >> num;
		usr.push(num);
	}
	while (!usr.empty()) {
		std::cout << usr.top() << ' ';
		usr.pop();
	}
	std::cout << '\n';

	return 0;
}
