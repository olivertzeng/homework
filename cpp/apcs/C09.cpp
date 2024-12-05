#include <iostream>
#include <map>
#include <string>

int main (int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string s;
	std::map<char, int> co;
	std::cin >> s;
	for(auto &c : s) {
		if (co.find(c) == co.end())
			co[c] = 1;
		else
			co[c]++;
	}

	return 0;
}
