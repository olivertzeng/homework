#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long usr;
	std::cin >> usr;
	while (!(usr % 2)) usr /=2;
	std::cout << usr << "\n";

	return 0;
}
