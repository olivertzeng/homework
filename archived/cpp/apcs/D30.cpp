#include <bits/stdc++.h>

void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		std::cout << "Move ring " << 1 << " from " << a << " to " << c << "\n";
	} else {
		hanoi(n - 1, a, c, b); // 將上方的盤子移到b
		std::cout << "Move ring " << n << " from " << a << " to " << c << "\n";
		// 移動最下層的盤子n到c
		hanoi(n - 1, b, a, c); // 從b移動剩下的盤子到c
	}
}

int main() {
	int n;
	std::cin >> n;
	hanoi(n, 'A', 'B', 'C');
}
