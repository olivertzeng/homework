#include <stdio.h>

int main() {
	long double n;
	scanf("%Lf", &n);
	char grade = n > 89	  ? 'S'
				 : n > 79 ? 'A'
				 : n > 69 ? 'B'
				 : n > 59 ? 'C'
				 : n > 49 ? 'D'
				 : n > 39 ? 'E'
						  : 'F';
	printf("%c\n", grade);
	return 0;
}
