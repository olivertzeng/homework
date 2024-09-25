#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long sum = 0;
	for (int i = 0; i < 5; i++) {
		long long num;
		std::cin >> num;
		sum += num;
		std::cout << num << (i >= 4 ? "" : "+");
	}
	std::cout << '=' << sum << '\n';

	return 0;
}
