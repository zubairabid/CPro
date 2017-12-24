#include <stdio.h>
//#include <string.h>
//#include <math.h>

int main() {
	//defvals
	long long int i, j, k, T, N;

	scanf("%lld", &N);

	/*
	default constructs
	
	long long int i, j, k, T, N;

	//Input into N
	scanf("%lld", &N);

	
	//Loop from 0 -- > N-1
	for(i = 0; i < N; i++) {
		
	}
	
	Print statement
	printf("%lld\n", N);
	
	*/
	return 0;
}
/*

dp[n][k] = max(dp[n-1][k-1], dp[n-1][k])

N = 5, k = 3
6 10 8 4 2: --> index from 1
j = 2, i = 1
6
j = 1, i = 2
6  
   16
j = 0, i = 3

if(a[i] < 0)
	skip;
if(j == 0)
	fringe 
dp[i][j] = max(a[i] + dp[i-1][j-1], dp[i-1][k])

6 10 8 4 2

6  10 8  4  2
6  16 18 18 18
6  16 







*.