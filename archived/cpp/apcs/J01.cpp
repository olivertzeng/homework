#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	int max = 0, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			cnt++;
		} else {
			max = std::max(max, cnt);
			cnt = 1;
		}
	}
	max = std::max(max, cnt);
	std::cout << max << '\n';
	return 0;
}
