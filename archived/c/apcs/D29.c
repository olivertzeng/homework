#include <stdio.h>

int main(int argc, char *argv[]) {
	int usr, t = 0;
	scanf("%d", &usr);
	while (usr != 1) {
		if (usr % 2) {
			usr = 3 * usr + 1;
		} else {
			usr /= 2;
		}
		t++;
	}
	printf("%d\n", t);
	return 0;
}
