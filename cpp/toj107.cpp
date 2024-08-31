#include <bits/stdc++.h>

int n = 30;
int main(int argc, char *argv[]) {
	int tot = n;
	tot += n * (n + 1) * 0.5;
	for (int i = 1; i <= n; i++) {
		tot += pow(i, 2) * (i + 1) * 0.5;
	}
	std::cout << tot << "\n";
	return 0;
}
