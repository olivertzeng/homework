#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, menu[5] = {0};
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		if (temp >= 0 && temp <= 5) {
			menu[temp]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << menu[i] << (i == 4 ? "\n" : " ");
	}

	return 0;
}
