#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int t, n;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin.ignore(4);
		std::cin >> n;
		int usr[n][n];
		bool flag = true;
		for (auto &sub : usr)
			for (auto &num : sub)
				std::cin >> num;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				if (usr[j][k] != usr[n - j - 1][n - k - 1]) {
					std::cout << "Test #" << i + 1 << ": Non-symmetric.\n";
					flag = false;
					break;
				}
			if (!flag)
				break;
		}
		if (flag)
			std::cout << "Test #" << i + 1 << ": Symmetric.\n";
	}

	return 0;
}
