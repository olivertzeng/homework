#
#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, tmp = 0;
	scanf("%d", &n);
	int usr[n];
	int cmp1, cmp2, ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &usr[i]);
	}

	cmp1 = usr[0];
	cmp2 = usr[1];
	for (int i = 0; i < n; i++) {
		if (cmp1 > cmp2) {
			tmp++;
			if (tmp >= ans)
				ans = tmp;
			if (i + 2 < n)
				cmp2 = usr[i + 2];
		} else {
			if (i + 1 < n) {
				cmp1 = usr[i + 1];
				cmp2 = usr[i + 2];
			}
			if (tmp >= ans)
				ans = tmp;
			tmp = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
