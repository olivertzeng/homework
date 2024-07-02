#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, c = 0, t = 0;
	scanf("%d", &n);
	if (n % 2) {
		t = 30 * n + 10;
		c = (n - 1) / 2;
	} else {
		t = 30 * n;
		c = n / 2;
	}
	printf("c = %d\n", c);
	printf("t = %d\n", t);
	return 0;
}
