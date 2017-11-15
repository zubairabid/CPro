#include <stdio.h>
//#include <string.h>
//#include <math.h>

long long int A[1000007];
long long int track[1000007];

int main() {
	//defvals
	long long int i, j, k=1, M, T, N, tr = 0, c = -1, max = 0;

	scanf("%lld %lld", &N, &M);

	for(i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		if(A[i] == 1) {
			k = 1;
		}
		else {
			track[i] = k++;
			if(k > M) {
				k = 1;
			}
		}
	}

	for(i = 0; i < N; i++) {
		printf("%lld - ", track[i]);
	}
	printf("\n");

	for(i = 0; i <= N; i++) {
		c++;
		if(track[i] >= 1) {
			tr++;
		}
		if(tr > M-1 || i == N) {
			if(c > max) {
				max = c;
			}
			if(c == M) {
				tr = 0;
				c = 0;
				break;
			}
			tr = 0;
			c = c - T - 1;
		}
		if(track[i] == 1) {
			T = i;
		}
	}

	printf("%lld\n", max);

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
