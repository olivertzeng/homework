#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, ans[5], p = 0;
	for (auto &num : ans)
		num = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int usr;
		std::cin >> usr;
		switch (usr) {
		case 0:
			std::cout << ans[p] << '\n';
			break;
		case 1:
			ans[p]++;
			break;
		case 2:
			p = (p + 1) % 5;
			break;
		case 3:
			p = (p + 4) % 5;
			break;
		}
	}

	return 0;
}
