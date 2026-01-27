#include <stdio.h>

long long factorial(int n) {
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

long long combination(int n, int r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
	int n, r;
	scanf("%d %d", &n, &r);

	long long result = combination(n, r);
	if (result != -1) {
		printf("%lld\n", result);
	}

	return 0;
}
