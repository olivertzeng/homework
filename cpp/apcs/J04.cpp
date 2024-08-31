#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
	long long n;
	std::cin >> n;

	std::vector<std::pair<long long, long long>> customers(n);
	for (auto &[a, b] : customers) {
		std::cin >> a >> b;
	}
	sort(customers.begin(), customers.end());
	std::vector<long long> rooms;
	for (const auto &[a, b] : customers) {
		bool assigned = false;
		for (auto &room : rooms) {
			if (a >= room) {
				room = b;
				assigned = true;
				break;
			}
		}
		if (!assigned) {
			rooms.push_back(b);
		}
	}

	std::cout << rooms.size() << "\n";
	for (int i = 0; i < customers.size(); ++i) {
		std::cout << i + 1 << " ";
	}
	std::cout << "\n";

	return 0;
}
