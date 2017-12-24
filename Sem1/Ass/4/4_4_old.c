#include <stdio.h>

long long int k, N, count= 0;
long long int store[1010][1010];
long long int len[1010];
long long int dp[1010][1010];

long long int gen(long long int, long long int, long long int);

int main() {
	
	long long int i, j, T, b;
 
	scanf("%lld %lld", &N, &k);
	T=0;
	b=1;
	for (i = 0; i < N; ++i)
	{
		j = 0;
		while(T+b <= N) {
			store[i][j++] = T+b;
			T=T+b;
		}
		len[i] = j;
		b++;
		T=0;
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < len[i]; ++j)
		{
			printf("%lld ", store[i][j]);
		}
		printf("\t\t len = %lld\n", len[i]);
		printf("\n");
	}
	
	for (i = 0; i < len[0]; ++i)
	{
		gen(i, i, 1);
	}
	//gen(0, 0, 1);

	printf("%lld\n", count);
	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/

	return 0;
}


long long int gen(long long int a1, long long a2, long long int level) {
	printf("entering level %lld with %lld. Max: %lld \n",level, a1, len[a1]);
	if(dp[level][a1] != 0) {
		printf("For level:%lld var:%lld, we have %lld\n", level, a1, dp[level][a1]);
		return dp[level][a1];
	}
	long long int temp = 0;
	long long int i;
	if(level == k-1) {
		count = (count+len[a1])%1000000007;
		printf("exiting level %lld, count+=%lld. count=%lld \n",level, len[a1], count);
		return len[a1];
	}
	//long long int *arr = store[a1][0];
	for(i = a2; i < len[a1]+a2; i++) {
		dp[level][a2] = gen(i, i, level+1);
		temp += dp[level][a2];
		//count = (count+temp)%1000000007;
	}
	
	printf("exiting level %lld \n",level );
	return temp;
}