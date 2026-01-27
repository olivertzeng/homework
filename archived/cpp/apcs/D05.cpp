#include <bits/stdc++.h>

double BMI(double w, double h) {
	double bmi = w / h / h;
	return bmi;
}

int main() {
	double w, h;
	std::cin >> w >> h;
	std::cout << std::fixed << std::setprecision(3) << BMI(w, h) << '\n';
}
