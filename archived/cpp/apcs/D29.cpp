#include "bits/stdc++.h"

int main(int argc, char *argv[]) {
	int usr, t = 0;
	std::cin >> usr;
	while (usr != 1) {
		if (usr % 2) {
			usr = 3 * usr + 1;
		} else {
			usr /= 2;
		}
		t++;
	}
	std::cout << t << "\n";
	return 0;
}
