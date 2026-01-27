#include <iostream>
#include <string>
#include <variant>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::string usr = std::to_string(n);
	if (n % k && usr.find(k + '0') == std::variant_npos)
		std::cout << "NO\n";
	else
		std::cout << "YES\n";

	return 0;
}
