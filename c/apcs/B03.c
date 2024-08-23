#include <math.h>
#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d = b * b - 4 * a * c;
	if (d < 0 && a) {
		printf("No real root");
	} else if (d == 0 && a) {
		printf("Two same roots x=%d", -b / (2 * a));
	} else if (a) {
		int a1 = (-b + sqrt(d)) / (2 * a);
		int a2 = (-b - sqrt(d)) / (2 * a);
		printf("Two different roots x1=%d , x2=%d", a1, a2);
	} else {
		printf("No real root");
	}
}
