#include <cstring>
#include <iostream>
#include <queue>
#include <string>

long long person[1000000];
int main() {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, m, a, t = 0;
	std::string s;
	std::queue<long long> team[1005], line;
	while (std::cin >> n) {
		memset(person, 0, sizeof(person));
		std::cout << "Line #" << ++t << "\n";
		for (int i = 1; i <= n; i++) {
			std::cin >> m;
			for (int j = 0; j < m; j++) {
				std::cin >> a;
				person[a] = i;
			}
		}
		while (std::cin >> s) {
			if (s == "STOP")
				break;
			if (s == "ENQUEUE") {
				std::cin >> a;
				if (person[a] == 0) {
					line.push(a + 1300);
				} else {
					if (team[person[a]].size() == 0) {
						line.push(person[a]);
					}
					team[person[a]].push(a);
				}
			} else {
				if (line.front() <= 1000) {
					std::cout << team[line.front()].front() << "\n";
					team[line.front()].pop();
					if (team[line.front()].size() == 0) {
						line.pop();
					}

				} else {
					std::cout << line.front() - 1300 << "\n";
					line.pop();
				}
			}
		}
	}
}
