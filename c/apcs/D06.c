#include <stdio.h>

int main(int argc, char *argv[]) {
	double usr, ans;
	scanf("%lf", &usr);
	ans = (usr - 32) * 5 / 9;
	printf("%.3lf\n", ans);
	return 0;
}
