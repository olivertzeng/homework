#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int num, rec = 0;
	while (std::cin >> num) {
		if (!num) {
			break;
		} else {
			if (!rec) {
				rec = num;
			} else if (rec % 7 && !(num % 7)) {
				rec = num;
			} else {
				if (num % 7 && rec % 7 && num % 77 < rec % 77) {
					rec = num;
				} else if (!(rec % 7) && !(num % 7) && num % 70 > rec % 70) {
					rec = num;
				}
			}
		}
	}
	std::cout << rec << "\n";
	return 0;
}
