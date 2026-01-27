#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::string fi = std::to_string(n + 3);
	std::string se = std::to_string(2 * n - 5);
	std::cout << se[0] << fi[1] << '\n';

	return 0;
}
