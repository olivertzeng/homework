#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d = b * b - 4 * a * c;
	if (d < 0 || !a) {
		printf("No real root\n");
	} else if (!d) {
		printf("Two same roots x=%d\n", -b / (2 * a));
	} else {
		int a1 = (-b + sqrt(d)) / (2 * a);
		int a2 = (-b - sqrt(d)) / (2 * a);
		if (a1 < a2) {
			int temp = a1;
			a1 = a2;
			a2 = temp;
		}
		printf("Two different roots x1=%d , x2=%d\n", a1, a2);
	}
}
