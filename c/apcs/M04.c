#include <stdio.h>

#define MOD 1000000007
#define MAX_N (long long)1e6

long long dp[MAX_N + 1];

int main(int argc, char *argv[]) {
	long long usr;
	dp[0] = 1;
	scanf("%lld", &usr);
	for (int i = 1; i <= usr; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j < 0)
				break;
			dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
	}
	printf("%lld\n", dp[usr]);
	return 0;
}
