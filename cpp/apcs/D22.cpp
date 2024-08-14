#include <bits/stdc++.h>

char s[1005], t[1005];

int main(int argc, char *argv[]) {
	char c;
	int idx = 0;
	while (std::cin >> c) {
		s[idx] = c, t[idx] = c;
		idx++;
	}

	std::reverse(t, t + idx);

	bool ok = 1;
	for (int i = 0; i < idx; i++) {
		if (s[i] != t[i])
			ok = 0;
	}

	std::cout << (ok ? "yes" : "no") << "\n";
	return 0;
}
