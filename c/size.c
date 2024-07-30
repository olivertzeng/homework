#include <stdio.h>

int main(int argc, char *argv[]) {
	int nums[] = {10, 20, 30, 40};
	int total = sizeof(nums);
	int number = total / sizeof(int);

	printf("total size in bytes = %d\n", total);
	printf("number = %d\n", number);
	return 0;
}
