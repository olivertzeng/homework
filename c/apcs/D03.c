#include <stdio.h>

int main(int argc, char *argv[]) {
	int usr, sum = 0;
	scanf("%d", &usr);
	for (int i = 1; i < usr; i++) {
		if (usr % i == 0) {
			sum += i;
		}
	}
	if (sum > usr) {
		printf("abundant\n");
	} else if (sum < usr) {
		printf("deficient\n");
	} else {
		printf("perfect\n");
	}
	return 0;
}
