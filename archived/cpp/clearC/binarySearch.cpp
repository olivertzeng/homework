#include <bits/stdc++.h>
using namespace std;

int main() {
	long long ans, high = 100, low = 1, mid;
	bool found = false;
	cout << "Please enter the number you want me(as a computer) to search: ";
	cin >> ans;
	while (high >= low) {
		mid = low + (high - low) / 2;
		if (mid > ans) {
			cout << "Guessed " << mid << " was higher than " << ans << '\n';
			high = mid - 1;
		} else if (mid < ans) {
			cout << "Guessed " << mid << " was lower than " << ans << '\n';
			low = mid + 1;
		} else {
			cout << "Guessed " << mid << " was equal to " << ans << '\n';
			found = true;
			break;
		}
	}
	if (found) {
		cout << "Your number " << ans
			 << " was between 100-1 duh(should've just used ans > 100 || ans < "
				"1 but whatever)"
			 << '\n';
	} else {
		cout << "Your number " << ans
			 << " was not between 100-1 duh(should've just used ans > 100 || "
				"ans < 1 but whatever)"
			 << '\n';
	}
}
