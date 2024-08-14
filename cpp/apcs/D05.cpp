#include <bits/stdc++.h>
using namespace std;

double BMI(double w, double h) {
	double bmi = w / h / h;
	return bmi;
}

int main() {
	double w, h;
	cin >> w >> h;
	cout << fixed << setprecision(3) << BMI(w, h) << endl;
}
