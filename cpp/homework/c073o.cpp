#include <deque>
#include <iostream>
#include <stack>

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

		while (std::cin >> commandA && commandA != "quit") {
			std::cin >> a >> commandB >> b;
			int ada = ad[a], adb = ad[b];
			bool isa = false;
			std::stack<int> buf;
			if (a != b && ada != adb) {
				if (commandA == "move")
					while (blocks[ada].size() && blocks[ada].front() != a) {
						int temp = blocks[ada].front();
						blocks[ada].pop_front();
						blocks[temp].push_front(temp);
						ad[temp] = temp;
					}
				if (commandB == "onto")
					while (blocks[adb].size() && blocks[adb].front() != b) {
						int temp = blocks[adb].front();
						blocks[adb].pop_front();
						blocks[temp].push_front(temp);
						ad[temp] = temp;
					}
				while (blocks[ada].size() && !isa) {
					int temp = blocks[ada].front();
					buf.push(temp);
					ad[temp] = adb;
					blocks[ada].pop_front();
					isa = temp == a;
				}
				while (buf.size()) {
					blocks[adb].push_front(buf.top());
					buf.pop();
				}
			}
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
