#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> usr(n), sorted(n);
	vector<bool> checked(n, false);

	for (auto &e : usr) {
		cin >> e;
	}

	for (int i = 0; i < n; i++) {
		int maxI = -1;
		for (int j = 0; j < n; j++) {
			if (!checked[j]) {
				if (maxI == -1 || usr[j] >= usr[maxI]) {
					maxI = j;
				}
			}
		}
		sorted[i] = usr[maxI];
		checked[maxI] = true;
	}

	for (auto &e : sorted) {
		cout << e << '\n';
	}
}
