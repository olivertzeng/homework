#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int main(int argc, char *argv[]) {
	int ans = 1, n, tmp = 1, x = -1, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &y);
		if (y < x && x > 0) {
			tmp++;
		} else {
			tmp = 1;
		}
		ans = max(tmp, ans);
		x = y;
	}

	printf("%d\n", ans);
	return 0;
}
