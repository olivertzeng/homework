#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long m, n, a = 0;
	std::cin >> m >> n;
	while (m < n){
        m *= 3;
        a++;
	}
	std::cout << a << "\n";

	return 0;
}
