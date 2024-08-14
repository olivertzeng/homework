#include <stdio.h>

int leolion(int usr) {
	if (!usr)
		return 0;
	if (usr == 1)
		return 1;
	return leolion(usr - 1) + leolion(usr - 2);
}

int main(int argc, char *argv[]) {
	int usr;
	scanf("%d", &usr);
	printf("%d\n", leolion(usr));
	return 0;
}
