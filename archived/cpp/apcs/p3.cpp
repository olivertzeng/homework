#include <iostream>
#include <string>

const long long MAX = (long long)2e5;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	long long n, k, m = MAX;
	std::string str, bak;
	std::cin >> n;
	std::cin >> str;
	bak = str;
	for (long long i = 1; i <= n; i++) {
		long long tmp = 0;
		str = bak;
		for (long long j = 0; j <= n; j++) {
			if (str[j] == '0') {
				for (long long k = j; k < j + i; k++)
					if (k <= n) {
						str[k] = (str[k] == '0') ? '1' : '0';
					}
				tmp++;
			}
		}
		if (tmp < m) {
			m = tmp;
			k = i;
		}
	}
	std::cout << k << ' ' << m << '\n';
	return 0;
}
