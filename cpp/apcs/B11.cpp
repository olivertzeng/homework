#include <algorithm>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long usr[3], a, b, c;
	for (auto &var : usr) {
		std::cin >> var;
	}
	std::sort(usr, usr + 3);
	a = usr[0];
	b = usr[1];
	c = usr[2];

	if (a + b <= c) {
		std::cout << "無法形成三角形\n";
	} else if (a * a + b * b == c * c) {
		std::cout << "直角三角形\n";
	} else if (a == c) {
		std::cout << "正三角形\n";
	} else if (a == b || b == c) {
		std::cout << "等腰三角形\n";
	} else {
		std::cout << "普通三角形\n";
	}

	return 0;
}
