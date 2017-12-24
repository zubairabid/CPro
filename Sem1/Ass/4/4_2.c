#include <stdio.h>

long long int ledger[1010][1010];

int main() {
	
	long long int i, j, l, K, temp, N, max = 0, tmax = 0;
 
	scanf("%lld %lld", &N, &K);

	for(j = 0; j < N; j++) {
		scanf("%lld", &ledger[0][j]); // taking input
	}

	for(i = 2; i <= K+1; i++) { //filling the ledger accordingly
		max = 0;
		for(j = 1; j < N; j++) {
			for(l = 0; l < j; l++) {
				temp = ledger[0][j] - ledger[0][l] + (l==0?0:ledger[i-1][l-1]);
				if(temp > max) {
					max = temp;
				}
			}
			ledger[i][j] = max;
		}
		if(max > tmax) {
			tmax = max;
		}
	}

	printf("%lld\n", tmax);

	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/

	return 0;
}