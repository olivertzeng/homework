#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		std::vector<int> parking;
		std::cin >> a >> b >> c;
		for (int i = a + 1; i < b; i++) {
			if (i % c) {
				parking.push_back(i);
			}
		}
		if (!parking.empty()) {
			for (int i = 0; i < parking.size(); i++) {
				std::cout << parking[i]
						  << (i + 1 == parking.size() ? "\n" : " ");
			}
		} else {
			std::cout << "No free parking spaces.\n";
		}
	}

	return 0;
}
