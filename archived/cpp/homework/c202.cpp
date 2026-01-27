#include <iostream>
#include <numeric>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string usr;
	int n;
	std::cin >> n;
	long long a, b[n - 1];
	std::cin >> a;
	for (auto &num : b)
		std::cin >> num;
	for (auto &num : b) {
		if (a == 1)
			break;
		a = std::gcd(a, num);
	}
	std::cout << a << '\n';

	return 0;
}
