#include <stdio.h>
int main(int argc, char *argv[]) {
	int usr;
	scanf("%d", &usr);
	if (usr > 0) {
		printf("1\n");
	} else if (usr) {
		printf("-1\n");
	} else {
		printf("0\n");
	}
	return 0;
}
