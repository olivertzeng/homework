#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	int n;
	std::cout << "Please input the number of layers: ";
	std::cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j > 0; j--) {
			std::cout << " ";
		}
		for (int j = 2 * (n - i) - 1; j > 0; j--) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	return 0;
}
