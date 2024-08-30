#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	long long a, r;
	scanf("%lld %lld", &r, &a);
	if (r == a) {
		a = 3;
	}
	if (r - a < a) {
		printf("%lld+%lld=%lld\n", r - a, a, r);
	} else {
		printf("%lld+%lld=%lld\n", a, r - a, r);
	}
	return EXIT_SUCCESS;
}
