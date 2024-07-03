#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b, n, num, result = 0;
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int A = 0, B = 0;
		while (scanf("%d", &num) == 1 && num != 0) {
			if (num == a) {
				A = 1;
			} else if (num == b) {
				B = 1;
			} else if (num == -a) {
				A = 0;
			} else if (num == -b) {
				B = 0;
			}
		}
		if (A && B) {
			result++;
		}
	}
	printf("result = %d\n", result);
	return 0;
}
