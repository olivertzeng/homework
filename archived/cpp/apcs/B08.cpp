#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int hr[3], min[3];
	std::cin >> hr[0] >> min[0] >> hr[1] >> min[1];
	std::cin >> hr[2] >> min[2];
	if (hr[2] > hr[1] || hr[2] < hr[0] || (hr[2] == hr[1] && min[2] > min[1]) ||
		(hr[2] == hr[0] && min[2] < min[0])) {
		std::cout << "Break\n";
	} else {
		std::cout << "Learning\n";
	}

	return 0;
}
