#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	bool result = (!(n % 4) && n % 100 || !(n % 400));
	std::cout << (result ? "YES\n" : "NO\n");

	return 0;
}
