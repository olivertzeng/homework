#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	if (n == 1) {
		std::cout << "嘿\n";
	} else if (n == 2) {
		std::cout << "fishhh\n";
	} else if (n == 3) {
		std::cout << "武漢肺炎座\n";
	} else if (n == 4) {
		std::cout << "2\n";
	} else if (n == 5) {
		std::cout << "tomato\n";
	} else if (n == 6) {
		std::cout << "hard to hear\n";
	} else if (n == 7) {
		std::cout << "17\n";
	} else {
		std::cout << "外孫\n";
	}

	return 0;
}
