#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string a, b;
	std::cin >> a >> b;
	int x = std::stoi(a), y = std::stoi(b);
	std::vector<int> ans;
	long long dp[10][b.size()];
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < b.size() + 1; j++) {
			if (j == 1 || i == 1)
				dp[i][j] = i;
			else
				dp[i][j] = dp[i][j - 1] * i;
		}
	}
	for (int i = x; i < y + 1; i++) {
		long long sum = 0;
		std::string temp = std::to_string(i);
		for (auto var : temp) {
			sum += dp[var + '0'][temp.size()];
		}
		if (sum == i) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) {
		std::cout << "none\n";
	} else {
		for (int i = 0; i < ans.size(); i++) {
			std::cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
		}
	}

	return 0;
}
