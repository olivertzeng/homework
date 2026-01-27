#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long n;
	std::cin >> n;

	std::vector<std::pair<long, long>> customers(n);
	for (auto &[a, b] : customers) {
		std::cin >> a >> b;
	}
	std::sort(customers.begin(), customers.end());
	std::vector<long> rooms;
	for (const auto &[a, b] : customers) {
		bool assigned = false;
		for (auto &room : rooms) {
			if (a > room) {
				room = b;
				assigned = true;
				break;
			}
		}
		if (!assigned) {
			rooms.push_back(b);
		}
	}

	std::cout << rooms.size() << '\n';
	return 0;
}
