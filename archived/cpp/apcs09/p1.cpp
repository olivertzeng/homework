#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n;
	double sum = 0;
	std::string grades[100];
	std::cin >> n;
	while (n--) {
		long long index;
		std::cin >> index >> grades[index];
	}

	for (auto &var : grades) {
		sum += var == "A+"	 ? 4.3
			   : var == "A"	 ? 4.0
			   : var == "A-" ? 3.7
			   : var == "B+" ? 3.3
			   : var == "B"	 ? 3.0
			   : var == "B-" ? 2.7
			   : var == "C+" ? 2.3
			   : var == "C"	 ? 2.0
			   : var == "C-" ? 1.7
			   : var == "D"	 ? 1.0
							 : 0;
	}

	std::cout << std::fixed << std::setprecision(1) << sum << '\n';

	return 0;
}
