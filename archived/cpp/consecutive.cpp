#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;
	for (size_t i = 0; i < n; ++i) {
		std::string usr;
		int total = 0;
		int times = 0;
		std::cin >> usr;
		for (size_t j = 0; j < usr.size(); ++j) {
			if (usr[j]) {
				times++;
				total += times;
			} else {
				times = 0;
			}
		}
		std::cout << total << "\n";
	}
	return 0;
}
