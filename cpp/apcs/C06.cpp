#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int k, q, r, temp;
	std::string s;
	std::cin >> k >> q >> r >> s;
	int op[q][k];
	char ans[q][k];
	for (auto &sub : op) {
		for (auto &num : sub) {
			std::cin >> num;
		}
	}

	for (int i = 0; i < k; i++) {
		temp = i;
		for (int j = 0; j < q; j++) {
			temp = op[j][temp] - 1;
			ans[j][i] = s[temp];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < q; j++) {
			std::cout << ans[j][i];
		}
		std::cout << '\n';
	}

	return 0;
}
