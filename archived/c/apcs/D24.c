#include <stdio.h>

long long dp[(long long)2e5];

/**
 * @brief function used with dynamic programming! kudos to Chung professor
 *
 * @param usr
 * @return
 */
long long chung(int usr) {
	if (!usr)
		return 0;
	if (usr == 1)
		return 1;
	if (dp[usr])
		return dp[usr];
	return chung(usr - 1) + chung(usr - 2);
}

int main(int argc, char *argv[]) {
	long long usr;
	scanf("%Ld", &usr);
	printf("%Ld\n", chung(usr));
	return 0;
}
