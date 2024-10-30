#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, votes[4] = {0};
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		if (temp > 3) {
			votes[3]++;
		} else {
			votes[temp - 1]++;
		}
	}
	for (int i = 0; i < 4; i++) {
		std::cout << votes[i] << (i == 3 ? "\n" : " ");
	}

	return 0;
}
