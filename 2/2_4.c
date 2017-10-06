#include <stdio.h>

long long int div(long long int, long long int, long long int);
int main(void) {
	long long int X, Y, M, T, i;
	scanf("%lld", &T);
	
	for(i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &X, &Y, &M);
		printf("%lld\n", div(X, Y, M));
	}
	return 0;
}

long long int div(long long int X, long long int Y, long long int M) {
	//printf("%lld p %lld mod %lld\n", X, Y, M);
	long long int d = 1;
	
	d = X%M;
	int f = 1;
	
	while(f<Y) {
		f*=2;
		if(f > Y) {
			d = d * div(X, (Y-(f/2)), M);
			d = d%M;
			break;
		}
		d = d*d;
		d %= M;
	}
	
	return d;
}
