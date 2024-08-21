#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	unsigned char msg[100], c;
	int key;

	printf("Please input message: ");
	scanf("%s", msg);
	printf("Please input the key: ");
	scanf("%d", &key);
	key %= 26;
	for (int i = 0; msg[i] != '\0'; i++) {
		c = msg[i];
		if (c >= 'a' && c <= 'z') {
			c += key;
			if (c > 'z')
				c -= 26;
		} else if (c >= 'A' && c <= 'Z') {
			c += key;
			if (c > 'Z')
				c -= 26;
		}
		msg[i] = c;
	}
	printf("\nEncrypted message: %s\n", msg);
	return EXIT_SUCCESS;
}
