#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	std::vector<long long> vt[n + 1];
	for (int i = 0; i < q; i++) {
		int op, x, y;
		long long w;
		std::cin >> op;
		switch (op) {
		case 1:
			std::cin >> x >> w;
			vt[x].push_back(w);
			break;
		case 2:
			std::cin >> x;
			if (vt[x].empty()) {
				std::cout << "Vector is empty!\n";
			} else {
				vt[x].pop_back();
			}
			break;
		case 3:
			std::cin >> x >> y >> w;
			vt[x].clear();
			vt[x].resize(y, w);
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vt[i].empty()) {
			std::cout << i << ": " << vt[i].size() << ' ';
			for (auto &var : vt[i]) {
				std::cout << var << ' ';
			}
			std::cout << '\n';
		}
	}

	return 0;
}
