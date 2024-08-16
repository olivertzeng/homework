#include <bits/stdc++.h>
#include <functional>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::set<int, std::greater<int>> unique_values = {a, b, c};
	std::vector<int> sorted_values(unique_values.begin(), unique_values.end());
	std::cout << 4 - unique_values.size() << " ";

	for (int value : sorted_values) {
		std::cout << value << " ";
	}
	std::cout << "\n";

	return 0;
}
