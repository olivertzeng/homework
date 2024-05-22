// Copyright (c) 2024 Oliver Tzeng. All Rights Reserved.

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cout << "Please input the number of layers: ";
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 2 * (n - i) - 1; j > 0; j--) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
