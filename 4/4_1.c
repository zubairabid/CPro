#include <stdio.h>

long long int fibgen[2][2]={{1, 1},{1, 0}};
long long int base[2][2]={{1, 1},{1, 0}};


void matmult(int dec);

int main() {
	long long int i, j, k, T, N;

	//scanf("%lld", &N); // we're supposed to work with the Nth number
	N=100000000009;
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
		}
		while(i < N) {
			i++;
			if(i > N) {
				i--;
				break;
			}
			matmult(1);	
		}
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

void matmult(int dec) {

	int z=0;
	int n=1;

	if(dec== 0) {
		long long int a00 = (fibgen[z][z]*fibgen[z][z] + fibgen[z][n]*fibgen[n][z])%1000000007 , a01 = (fibgen[z][z]*fibgen[z][n] + fibgen[z][n]*fibgen[n][n])%1000000007 , a10 = (fibgen[n][z]*fibgen[z][z] + fibgen[n][n]*fibgen[n][z])%1000000007 , a11  = (fibgen[n][z]*fibgen[z][n] + fibgen[n][n]*fibgen[n][n])%1000000007;
		fibgen[0][0] = a00;
		fibgen[0][1] = a01;
		fibgen[1][0] = a10;
		fibgen[1][1] = a11;
	}
	else {
		long long int a00 = (fibgen[z][z]*base[z][z] + fibgen[z][n]*base[n][z])%1000000007 , a01 = (fibgen[z][z]*base[z][n] + fibgen[z][n]*base[n][n])%1000000007 , a10 = (fibgen[n][z]*base[z][z] + fibgen[n][n]*base[n][z])%1000000007 , a11  = (fibgen[n][z]*base[z][n] + fibgen[n][n]*base[n][n])%1000000007;
		fibgen[0][0] = a00;
		fibgen[0][1] = a01;
		fibgen[1][0] = a10;
		fibgen[1][1] = a11;
	}

}
