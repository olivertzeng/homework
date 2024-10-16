#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <set>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int usr[3], count[10] = {0}, t = 0;
	std::deque<int> ans;
	std::set<int> uni;
	for (int i = 0; i < 3; i++) {
		std::cin >> usr[i];
		uni.insert(usr[i]);
		count[usr[i]]++;
	}
	std::sort(count, count + 10, std::greater<int>());
	std::cout << count[0] << ' ';
	for (auto &var : uni) {
		ans.push_front(var);
	}
	for (auto &var : ans) {
		t++;
		std::cout << var << (t == ans.size() ? "\n" : " ");
	}

	return 0;
}
