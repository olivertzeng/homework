#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; ++i) {
		string usr;
		int total = 0;
		int times = 0;
		cin >> usr;
		for (size_t j = 0; j < usr.size(); ++j) {
			if (usr[j]) {
				times++;
				total += times;
			} else {
				times = 0;
			}
		}
		cout << total << "\n";
	}
	return 0;
}
