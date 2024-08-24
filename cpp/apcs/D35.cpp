#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string strStart = "AAAAA AAAAA A AAAA AAAAA AAAA";
	std::string strEnd = "HELLO APCSS X APCS GUIDE CAMP";
	std::cout << strStart;
	for (int i = 0; i < strStart.size(); i++) {
		for (char j = 'B'; j <= strEnd[i]; j++) {
			std::cout << "\n";
			strStart[i] = j;
			for (auto var : strStart) {
				std::cout << var;
			}
		}
	}
	std::cout << "\n";
	return 0;
}
