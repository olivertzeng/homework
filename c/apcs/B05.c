#include <stdio.h>

int main() {
	long double n;
	scanf("%Lf", &n);
	char grade = n >= (long double)90	? 'S'
				 : n >= (long double)80 ? 'A'
				 : n >= (long double)70 ? 'B'
				 : n >= (long double)60 ? 'C'
				 : n >= (long double)50 ? 'D'
				 : n >= (long double)40 ? 'E'
										: 'F';
	printf("%c\n", grade);
	return 0;
}
