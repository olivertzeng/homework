#include <bits/stdc++.h>
using namespace std;

int n, stars, t, u;
int main(int argc, char *argv[]) {
	cin >> stars;
	while (stars--) {
		cin >> n;
		for (int i = 0; i < (2 * n - 3); i++) {
			// the number of spaces
			t = abs(n - i - 2) + 1;
			if (t == 2) {
				t = 0;
			}
			// the number of stars
			u = 2 * (n - t);
			while (t--) {
				cout << " ";
			}
			while (--u) {
				cout << "*";
			}
			cout << "\n";
		}
	}
	return 0;
}
