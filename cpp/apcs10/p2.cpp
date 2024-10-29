#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, c = 0;
	std::string m;
	std::cin >> n;
	std::vector<std::string> usr(n);
	for (auto &var : usr) {
		std::string o;
		std::cin >> o >> var;
	}
	std::cin >> m;
	for (auto &var : usr) {
		if (m.find(var) != std::string::npos) {
			c++;
		}
		std::cout << c << "\n";
	}

	return 0;
}
