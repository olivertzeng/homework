#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	int buf = 2;
	while (buf % 71) {
		buf *= 2;
		buf++;
	}
	if (buf % 3) {
		std::cout << "turn left\n";
	} else {
		std::cout << "turn right\n";
	}
	return 0;
}
