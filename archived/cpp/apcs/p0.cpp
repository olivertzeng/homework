#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cout << "Hello ASOJ!                                              "
					 "    \n";
	}
	return 0;
}
