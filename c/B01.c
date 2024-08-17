#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	if (n < 11) {
		printf("%d\n", n * 6);
	} else if (n < 21) {
		printf("%d\n", 2 * n + 40);
	} else if (n < 40) {
		printf("%d\n", n + 60);
	} else {
		printf("100\n");
	}
	return 0;
}
