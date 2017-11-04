#include <stdio.h>
long long int dp[1000000008];
int main() {
	long long int i, N, flag = 0;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	scanf("%lld", &N);
	//N=1																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												08;
	if(N==1 || N==2) {																																																																																																																																					
		printf("1\n");
	}

	for(i = 3; i <= N; i++) {
		if(dp[i] == 0) {
			dp[i] = (dp[i-1] + dp[i-2])%1000000007;
		}
		//for debugging:
		//if(dp[i] < dp[i-1])
		//	flag = 1;
		//printf("%lld:\t%lld\t--\t%lld\n", i, dp[i], flag);
	}

	printf("%lld\n", dp[N]);

	return 0;
}