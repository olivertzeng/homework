#include <bits/stdc++.h>
#include <numeric>

int main() {
	long long a, b, c;
	std::cin >> a >> b >> c;
	std::cout << std::gcd(std::gcd(a, b), c) << '\n';
}
