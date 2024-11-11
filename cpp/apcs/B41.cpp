#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, rec = 1, temp, sum = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (rec > temp)
			sum += (rec - temp) * 2;
		else
			sum += (temp - rec) * 3;
		rec = temp;
	}
	std::cout << sum << '\n';

	return 0;
}
