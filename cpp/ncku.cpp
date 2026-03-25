#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::map<long long, std::pair<std::string, long long>> people;

	int times;
	std::cin >> times;
	for (int i = 0; i < times; i++) {
		std::string name, stringQ1, stringQ2;
		long long action, id, color, longQ1, longQ2, temp1, temp2;
		std::vector<std::vector<long long>> friends;
		std::cin >> action;
		switch (action) {
		case 1:
			std::cin >> name >> id >> color;
			people[id] = {name, color};
			break;
		case 2:
			std::cin >> longQ1;
			std::cin >> people[longQ1].first;
			break;
		case 3:
			std::cin >> longQ1 >> longQ2;
			for(auto &subset : friends) {
				for(auto &element : subset) {
					if (element == longQ1) {

					}
				}
			}
		case 4:
			std::cin >> stringQ1 >> stringQ2;
			break;
		case 9:
			std::cin >> stringQ1;
			for(auto &element : people) {
				if (element.second.first == stringQ1) {
					std::cout << element.second.second << '\n';
				}
			}
			break;
		}
	}

	return 0;
}
