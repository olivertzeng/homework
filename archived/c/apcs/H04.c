#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }

int main(int argc, char *argv[]) {
	int h[100], n, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	if (!h[0]) {
		m += h[1];
	}
	if (!h[n - 1]) {
		m += h[n - 2];
	}

	for (int i = 0; i < n - 2; i++) {
		if (!h[i + 1]) {
			m += min(h[i + 2], h[i]);
		}
	}

	printf("%d\n", m);
	return EXIT_SUCCESS;
}
