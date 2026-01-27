#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int higher, int lower, int target, int li[100000]) {
	int mid = (higher + lower) / 2;
	if (higher < lower)
		return 0;
	else if (target == li[mid])
		return mid;
	else if (target > li[mid])
		return binarySearch(higher, mid + 1, target, li);
	else
		return binarySearch(mid - 1, lower, target, li);
}

int main(int argc, char *argv[]) {
	int k, n, q;
	scanf("%d %d", &n, &k);
	int ans[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &ans[i + 1]);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &q);
		printf("%d\n", binarySearch(n, 1, q, ans));
	}
	return EXIT_SUCCESS;
}
