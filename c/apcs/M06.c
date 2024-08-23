#include <stdio.h>

#define MOD 998244353
#define MAX_N 20000000

long long dp[MAX_N + 1];

long long chung(int n) {
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	return dp[n];
}

int main(int argc, char *argv[]) {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < k; i++) {
		long long usr;
		scanf("%lld", &usr);
		printf("%lld\n", chung(usr));
	}
	return 0;
}
