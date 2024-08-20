
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<pair<long long, long long>> customers(n);
	for (auto &[a, b] : customers) {
		cin >> a >> b;
	}

	sort(customers.begin(), customers.end());

	vector<long long> rooms;
	for (const auto &[a, b] : customers) {
		bool assigned = false;
		for (auto &room : rooms) {
			if (a >= room) {
				room = b;
				assigned = true;
				break;
			}
		}
		if (!assigned) {
			rooms.push_back(b);
		}
	}

	cout << rooms.size() << "\n";
	for (int i = 0; i < customers.size(); ++i) {
		cout << i + 1 << " ";
	}
	cout << "\n";

	return 0;
}
