#include <stdio.h>
#include <math.h>

long long int fibgen[2][2]={{1, 1},{1, 0}};
long long int base[2][2]={{1, 1},{1, 0}};

long long int dp[10000000]; //stores fibo no. 2^i in index i


void matmult(long long int dec);

int main() {
	long long int i, j, k, c, T, N;
	dp[0] = 1;
	c=1;
	scanf("%lld", &N); // we're supposed to work with the Nth number
	//N=1000000009;
	if(N==1)
		printf("1\n");
	else{
		i=1;

		while(i < N) {
			i*=2;
			if(i > N) {
				i/=2;
				break;
			}
			matmult(0);
			dp[c++] = fibgen[0][1];
			printf("fib#2^%lld is %lld\n", (c-1), dp[c-1]);
			printf("\t\t\t%lld %lld\n\t\t\t%lld %lld\n", fibgen[0][0], fibgen[0][1], fibgen[1][0], fibgen[1][1]);
			printf("\t\t\t%lld %lld\n\t\t\t%lld %lld\n", dp[c-2], dp[c-1], dp[c-1], dp[c]);
		
		}

		long long int temp=i;
		printf("Stopped doubling at: %lld for %lld iterations\n", temp, (N-temp));
		printf("\t\t\t%lld %lld\n\t\t\t%lld %lld\n", dp[c-2], dp[c-1], dp[c-1], dp[c]);
		
		k = c-2;
		while (i < N && k > 1) {
			
			i+=pow(2, k);
			if(i > N) {
				i -= pow(2, k);
				k--;
				continue;
			}
			matmult(k);

			printf("\t\t\t%lld %lld\n\t\t\t%lld %lld\n", fibgen[0][0], fibgen[0][1], fibgen[1][0], fibgen[1][1]);	
			printf("fib#%lld is %lld\n", (i), fibgen[0][1]);
		}
		while(i < N) {
			//printf("Entered the zone of tediousness at %lld\n", i);
			//for (k = 0; k < 100000; ++k)
			//{
				/* code */
			//}
			i++;
			if(i > N) {
				i--;
				break;
			}
			matmult(-1);	
		}
		printf("Stopped at: %lld for %lld iterations\n", temp, (N-temp));
		printf("%lld %lld\n%lld %lld\n", fibgen[0][0], fibgen[0][1], fibgen[1][0], fibgen[1][1]);
		printf("%lld\n", fibgen[0][1]);
		/*
		   for(i = 0; i < N; i++) {

		   }

		   printf("%lld\n", N);
		 */
	}

	return 0;
}

void matmult(long long int dec) {

	int z=0;
	int n=1;

	if(dec== 0) {
		long long int a00 = (fibgen[z][z]*fibgen[z][z] + fibgen[z][n]*fibgen[n][z])%1000000007 , a01 = (fibgen[z][z]*fibgen[z][n] + fibgen[z][n]*fibgen[n][n])%1000000007 , a10 = (fibgen[n][z]*fibgen[z][z] + fibgen[n][n]*fibgen[n][z])%1000000007 , a11  = (fibgen[n][z]*fibgen[z][n] + fibgen[n][n]*fibgen[n][n])%1000000007;
		fibgen[0][0] = a00;
		fibgen[0][1] = a01;
		fibgen[1][0] = a10;
		fibgen[1][1] = a11;
	}
	else if(dec==-1) {
		long long int a00 = (fibgen[z][z]*base[z][z] + fibgen[z][n]*base[n][z])%1000000007 , a01 = (fibgen[z][z]*base[z][n] + fibgen[z][n]*base[n][n])%1000000007 , a10 = (fibgen[n][z]*base[z][z] + fibgen[n][n]*base[n][z])%1000000007 , a11  = (fibgen[n][z]*base[z][n] + fibgen[n][n]*base[n][n])%1000000007;
		fibgen[0][0] = a00;
		fibgen[0][1] = a01;
		fibgen[1][0] = a10;
		fibgen[1][1] = a11;
	}
	else {
		long long int a00 = (fibgen[z][z]*fibgen[z][n] + fibgen[z][n]*dp[dec])%1000000007 , a01 = (fibgen[z][z]*dp[dec] + fibgen[z][n]*(fibgen[0][1] - dp[dec]))%1000000007 , a10 = (fibgen[n][z]*fibgen[z][n] + fibgen[n][n]*dp[dec])%1000000007, a11 = (fibgen[n][z]*dp[dec] + fibgen[n][n]*(fibgen[0][1] - dp[dec]))%1000000007;
		fibgen[0][0] = a00;
		fibgen[0][1] = a01;
		fibgen[1][0] = a10;
		fibgen[1][1] = a11;
		printf("Multiplied\t\t%lld %lld\n\t\t%lld %lld\nand\t%lld %lld\n\t%lld %lld", fibgen[0][0], fibgen[0][1], fibgen[1][0], fibgen[1][1], fibgen[0][1], dp[dec], dp[dec], (fibgen[0][1] - dp[dec]));

	}

}
