#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b, n, num, result = 0;
	scanf("%d %d", &a, &b);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int A = 0, B = 0;
		while (scanf("%d", &num) == 1 && num != 0) {
			if (num == a) {
				A++;
			} else if (num == -a) {
				A--;
			} else if (num == b) {
				B++;
			} else if (num == -b) {
				B--;
			}
		}
		if (A > 0 && B > 0) {
			result++;
		}
	}

	printf("%d\n", result);
	return 0;
}
