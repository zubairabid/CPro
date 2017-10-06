#include <stdio.h>

long long int div(long long int, long long int, long long int);

int main(void) {
	long long int X, Y, M, T, i;
	scanf("%lld", &T);
	
	for(i = 0; i < T; i++) {
		//printf("Working on test case %lld\n", (i+1));
		scanf("%lld %lld %lld", &X, &Y, &M);
		printf("%lld\n", div(X, Y, M));
	}
	return 0;
}

long long int div(long long int X, long long int Y, long long int M) {
	//printf("%lld p %lld mod %lld\n", X, Y, M);
	if(Y==1) {
	//	printf("(Base) Returning %lld\n", (X&M));
		return (X%M);
	}
	int p = 1;
	//printf("Going left. ");
	p *= div(X, Y/2, M);
	//printf("Going right. ");
	p *= div(X, Y-Y/2, M);
	p %= M;
	//printf("Returning %lld\n", (p));
	return p;
}
