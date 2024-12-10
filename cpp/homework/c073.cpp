#include <deque>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, a, b;
	std::string commandA, commandB;
	while (std::cin >> n) {
		std::cin >> commandA;
		int ad[n];
		std::deque<int> blocks[n];
		for (int i = 0; i < n; i++)
			ad[i] = i;
		for (int i = 0; i < n; i++)
			blocks[i].push_back(i);

		while (commandA != "quit") {
			std::cin >> a >> commandB >> b;
			int ada = ad[a], adb = ad[b];
			if (a != b && ada != adb) {
				if (commandA == "move")
					while (blocks[ada].size() && blocks[ada].front() != a) {
						int buf = blocks[ada].front();
						blocks[ada].pop_front();
						blocks[buf].push_front(buf);
						ad[buf] = buf;
					}
				if (commandB == "onto")
					while (blocks[adb].size() && blocks[adb].front() != b) {
						int buf = blocks[adb].front();
						blocks[adb].pop_front();
						blocks[buf].push_front(buf);
						ad[buf] = buf;
					}
				while (blocks[ada].size()) {
					blocks[adb].push_front(blocks[ada].back());
					ad[blocks[ada].back()] = adb;
					blocks[ada].pop_back();
				}
			}
			std::cin >> commandA;
		}

		for (int i = 0; i < n; i++) {
			std::cout << i << ": ";
			while (blocks[i].size()) {
				std::cout << blocks[i].back()
						  << (blocks[i].size() == 1 ? "" : " ");
				blocks[i].pop_back();
			}
			std::cout << '\n';
		}
	}

	return 0;
}
