#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> jotaro(m, 0);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a == 1) {
			jotaro[c - 1] += b;
		} else if (jotaro[c - 1] > b) {
			jotaro[c - 1] -= b;
		} else {
			jotaro[c - 1] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		std::cout << jotaro[i] << (i + 1 == m ? "\n" : " ");
	}

	return 0;
}
