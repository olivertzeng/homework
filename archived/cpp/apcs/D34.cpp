#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::string strStart;
	for (int i = 0; i < n; i++) {
		strStart += '(';
	}
	for (int i = n; i < 2 * n; i++) {
		strStart += ')';
	}
	std::cout << strStart << '\n';
	return 0;
}
