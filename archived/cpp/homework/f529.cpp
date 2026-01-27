#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::map<long long, int> songs;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		long long vote;
		std::cin >> vote;
		if (songs.find(vote) == songs.end()) {
			songs[vote] = 1;
		} else {
			songs[vote]++;
		}
	}

	std::vector<std::pair<long long, int>> songsVec;
	for (auto &var : songs) {
		songsVec.push_back({var.second, var.first});
	}

	std::sort(songsVec.begin(), songsVec.end());
	std::cout << songsVec.back().second << ' ' << songsVec.back().first << '\n';

	return 0;
}
