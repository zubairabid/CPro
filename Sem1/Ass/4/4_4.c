#include <stdio.h>

long long int dp[3010][3010];
long long int N, k;
int main() {
	
	long long int i, j, T, length, last;
 
	scanf("%lld %lld", &N, &k);

	for(last = 1; last <= N; last++) {
		dp[k-1][last] = N/last;
	//	printf("dp[%lld][%lld] = %lld\n",k-1, last, dp[k-1][last]);
	} //initialised base case



	for(length = k-2; length >= 0; length--) {
		//printf("1 length:%lld\n", length);
		for(last = 1; last <= N; last++) {
			//printf("%lld : 2 last:%lld\n", dp[length][last], last);
			if(dp[length][last] == 0) {
				for(i = last; i <= N; i+=last) {
					//printf("3\n");
					dp[length][last] += dp[length+1][i];
					//printf("DP of length:%lld and last:%lld is %lld\n", length, last, dp[length][last]);
					dp[length][last] = dp[length][last] % 1000000007;
				}
			}
		}
	}

	printf("%lld\n", dp[0][1]);


	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/

	return 0;
}