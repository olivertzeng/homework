#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int h, m, s, t;
	std::cin >> h >> m >> s >> t;
	h += t * 3 / 2;
	h %= 36;
	m += t % 2 * 30;
	if (m < 0) {
		m += 60;
		h--;
	} else if (m >= 60) {
		m -= 60;
		h++;
	}
	if (h < 0) {
		h += 36;
	}

	std::cout << h << ':' << (m < 10 ? "0" : "") << m << ':'
			  << (s < 10 ? "0" : "") << s << '\n';

	return 0;
}
