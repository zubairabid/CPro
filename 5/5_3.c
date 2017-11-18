#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
long long int ar[5100];
long long int dp[5100][5100]; // 5009 stores n_max, 5008 n-1, 5007 n-2
long long int count[5100][5100];
#define MAX_ 5009
#define MAX_1 5008
#define MAX_2 5007


int main() {
	//defvals
	long long int i, j, T, N, K, answer = 1<<31, temp, t2;
	scanf("%lld %lld", &N, &K);

	for(i = 1; i <= N; i++) {
		scanf("%lld", &ar[i]);	
	}

	for(j = 1; j <= N; j++) { // iterating through every element

		for(i = 1; i <= j; i++) { // iterating through level foreach el ////////////////////////////////////////
			if(i >= K && i == j) {
				dp[i][j] = 0; //np
				continue;
			}
			if(dp[i-1][MAX_1] == dp[i-1][j-1] && count[i-1][j-1] < K) {
				count[i][j] = count[i-1][j-1] + 1;
			}
			else {
				count[i][j] = 1;
				if(j!=N) {
				T = dp[i-1][MAX_2];
				T = T + ar[j];
				dp[i][MAX_2] = dp[i][MAX_1];
				dp[i][MAX_1] = dp[i][MAX_];
				if(T > dp[i][j]) {	
					dp[i][j] = T;
				}
				
				if(T > dp[i][MAX_]) {
					dp[i][MAX_] = T;
				}	

				if(T > answer) {
					answer = T;
				}
		/*		printf(" \t \t");
			for(temp = 1; temp <= N; temp++) {
				printf("%lld\t", ar[temp]);
			}
			printf("\n \t");
			for(temp = 0; temp <= N; temp++)
			{
				printf("%lld\t", temp);
			}
			printf("\n");
			for(temp = 0; temp <= N; temp++) {
				printf("%lld\t", temp);
				for(t2 = 0; t2 <= N; t2++) {
					printf("%lld\t", dp[temp][t2]);
				}	
				printf("\t%lld\t%lld\t%lld", dp[temp][MAX_2], dp[temp][MAX_1], dp[temp][MAX_]);
				printf("\n \t");
				for(t2 = 0; t2 <= N; t2++) {
					printf("%lld\t", count[temp][t2]);
				}
				printf("\n");
			}
			printf("------------------------------\n");	*/
				continue;}
			}
			
			if(count[i][j] % K != 0) {
				T = dp[i-1][MAX_1];
			}
			else {
				T = dp[i-1][MAX_2];
			}
			T = T + ar[j];
			dp[i][MAX_2] = dp[i][MAX_1];
			dp[i][MAX_1] = dp[i][MAX_];
			/*
			t2 = ((((N/K)-1)/1)+1);
			if((i!=1) && ((t2*(K-1))+t2-1 > j)) {
				T = 1;
			}
			*/
			if(T > dp[i][j]) {	
				dp[i][j] = T;
			}
			
			if(T > dp[i][MAX_]) {
				dp[	i][MAX_] = T;
			}

			if(T > answer) {
				answer = T;
			}

/*
			printf(" \t \t");
			for(temp = 1; temp <= N; temp++) {
				printf("%lld\t", ar[temp]);
			}
			printf("\n \t");
			for(temp = 0; temp <= N; temp++)
			{
				printf("%lld\t", temp);
			}
			printf("\n");
			for(temp = 0; temp <= N; temp++) {
				printf("%lld\t", temp);
				for(t2 = 0; t2 <= N; t2++) {
					printf("%lld\t", dp[temp][t2]);
				}	
				printf("\t%lld\t%lld\t%lld", dp[temp][MAX_2], dp[temp][MAX_1], dp[temp][MAX_]);
				printf("\n \t");
				for(t2 = 0; t2 <= N; t2++) {
					printf("%lld\t", count[temp][t2]);
				}
				printf("\n");
			}
			printf("------------------------------\n");
		
*/		
		}
	}
	if(answer < 0) {
		answer = 0;
	}
	printf("%lld\n", answer);

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
