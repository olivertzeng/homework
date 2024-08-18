#include <cstring>
#include <iostream>
#include <queue>
#include <string>

long long person[1000];
int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, m, a, t = 0;
	std::queue<long long> team[1005], line;
	while (std::cin >> n) {
		memset(person, 0, sizeof(person));
		std::cout << "Line #" << ++t << "\n";
		for (int i = 0; i < n; i++) {
			std::cin >> m;
			for (int j = 0; j < m; j++) {
				std::cin >> a;
				person[a] = i;
			}
		}
		std::pmr::string s;
		while (std::cin >> s) {
			if (s == "STOP") {
				break;
			} else if (s == "ENQUEUE") {
				std::cin >> a;
				if (!person[a]) {
					line.push(a + 1300);
				} else if (!team[person[a]].size()) {
					line.push(person[a]);
				} else {
					team[person[a]].push(a);
				}
			} else if (line.front() <= 1000) {
				std::cout << team[line.front()].front() << "\n";
				team[line.front()].pop();
				if (!team[line.front()].size()) {
					line.pop();
				}
			} else {
				std::cout << line.front() - 1300 << "\n";
				line.pop();
			}
		}
	}

	return 0;
}
