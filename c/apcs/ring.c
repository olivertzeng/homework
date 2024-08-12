#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary) {
	if (n == 1) {
		printf("Move ring 1 from %c to %c\n", source, target);
		return;
	}
	hanoi(n - 1, source, auxiliary, target);
	printf("Move ring %d from %c to %c\n", n, source, target);
	hanoi(n - 1, auxiliary, target, source);
}

int main() {
	int rings; // Number of rings
	scanf("%d", &rings);
	hanoi(rings, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0;
}
