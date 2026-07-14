#include <stdio.h>
#define CAP_DIFF ('a' - 'A')

void allReverseCaps(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 'z' && str[i] >= 'a') {
			str[i] -= CAP_DIFF;
		} else if (str[i] <= 'Z' && str[i] >= 'A') {
			str[i] += CAP_DIFF;
		}
	}
}

int main(int argc, char *argv[]) {
	char usr[] = "Hello, World!\nHello, Everybody!";
	char *aaa = usr;
	aaa[0] = '1';
	for (int i = 0; usr[i] != '\0'; i++) {
		printf("%c", usr[i]);
	}
	printf("\n");
	for (int i = 0; usr[i] != '\0'; i++) {
		printf("%02x ", usr[i]);
	}

	printf("\n");
	allReverseCaps(usr);
	printf("%s\n", usr);

	return 0;
}
