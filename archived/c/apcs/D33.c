#include <stdio.h>

#define MOD 998244353
#define MAX (long long)1e6

long long dp[MAX + 1];

int main(int argc, char *argv[]) {
	long long usr;
	dp[0] = 1;
	dp[1] = 1;
	scanf("%lld", &usr);
	dp[0] = 1;
	for (int i = 1; i <= usr; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % MOD;
		}
	}
	printf("%lld\n", dp[usr]);
	return 0;
}
