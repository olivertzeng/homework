#include <stdio.h>

int main() {
	long double n;
	scanf("%Lf", &n);
	char grade = n >= 90   ? 'S'
				 : n >= 80 ? 'A'
				 : n >= 70 ? 'B'
				 : n >= 60 ? 'C'
				 : n >= 50 ? 'D'
				 : n >= 40 ? 'E'
						   : 'F';
	printf("%c\n", grade);
	return 0;
}
