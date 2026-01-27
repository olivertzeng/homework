#include <iostream>

bool prime(int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n;

	std::cin >> n;
	std::cout << (prime(n) ? "YES\n" : "NO\n");

	return 0;
}
