#include <iostream>
#include <vector>
std::vector<long long> a, b;

void calculate() {
	if (a.size() <= 1)
		return;
	b.resize(a.size() - 1);
	for (long long i = 0; i < a.size() - 1; i++) {
		b[i] = a[i] + a[i + 1];
	}
	a.pop_back();
	a = b;
	return;
}

int main() {
	long long n, q, m, rd;
	std::cin >> n >> q;
	for (long long i = 0; i < n; i++) {
		std::cin >> m;
		a.push_back(m);
	}
	while (q--) {
		std::cin >> rd;
		if (rd == 1) {
			calculate();
		} else if (rd == 2) {
			for (long long i = 0; i < a.size(); i++) {
				if (i == a.size() - 1) {
					std::cout << a[i];
				} else {
					std::cout << a[i] << " ";
				}
			}
			std::cout << '\n';
		} else
			break;
	}
	return 0;
}
