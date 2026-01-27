#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, tmp;
	scanf("%d", &n);
	int usr[n], ans[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &usr[i]);
	}
	for (int i = 0; i < n; i++) {
		ans[i] = usr[n - i - 1];
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
