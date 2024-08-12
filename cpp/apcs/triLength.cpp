#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	int n, t = 1;
	while (std::cin >> n) {
		int ans = 0;
		std::cout << "Case " << t++ << ": ";
		while (n--) {
			int a, b, c;
			std::cin >> a >> b >> c;
			if (a + b > c && b + c > a && a + c > b)
				ans++;
		}
	}
	return 0;
}
