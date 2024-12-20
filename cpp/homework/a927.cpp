#include <iostream>

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	for (int i = 1; i <=10; i++)
		std::cout << "hello" << ' ' << i << '\n';

	return 0;
}
