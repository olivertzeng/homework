#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long usr[n];
	for (auto &e : usr) {
		cin >> e;
	}
	for (int i = 0; i < k; i++) {
		int low = 0, high = n - 1, mid;
		bool found = false;
		long long q;
		cin >> q;
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (usr[mid] == q) {
				cout << mid + 1 << '\n';
				found = true;
				break;
			} else if (usr[mid] < q) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		if (!found) {
			cout << 0 << '\n';
		}
	}
}
