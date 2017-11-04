#include <stdio.h>

long long int res[2][2] = {{1, 1}, {1, 0}};
long long int base[2][2] = {{1, 1}, {1, 0}};

void square();
void mult();
void fibo(int);

int main() {
	long long int n;
	scanf("%lld", &n);

	fibo(n);

	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/
	printf("%lld\n", res[0][1]);
	
	return 0;
}

void fibo(int n) {
	if(n == 1)
		return;
	fibo(n/2);
	square();
	if(n%2==1)
		mult();
}

void square() {
	long long int a00 = (res[0][0]*res[0][0] + res[0][1]*res[1][0])%1000000007 , a01 = (res[0][0]*res[0][1] + res[0][1]*res[1][1])%1000000007 , a10 = (res[1][0]*res[0][0] + res[1][1]*res[1][0])%1000000007 , a11  = (res[1][0]*res[0][1] + res[1][1]*res[1][1])%1000000007;
	res[0][0] = a00;
	res[0][1] = a01;
	res[1][0] = a10;
	res[1][1] = a11;
}

void mult() {
	long long int a00, a01, a10, a11;
	a00 = res[0][0] + res[0][1];
	a01 = res[0][0];
	a10 = res[0][0];
	a11 = res[0][1];
	res[0][0] = a00;
	res[0][1] = a01;
	res[1][0] = a10;
	res[1][1] = a11;

}