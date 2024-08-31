#include <bits/stdc++.h>
#include <vector>

int n, buf;
std::vector<int> score;
int main(int argc, char *argv[]) {
	std::cin >> n;
	while (n--) {
		std::cin >> buf;
		score.push_back(buf);
	}
	std::sort(score.begin(), score.end(), std::greater<int>());
	std::cout << score[0] << "\n";
	return 0;
}
