#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

long long int div(long long int, long long int, long long int);

int main() {
	long long int T, X, Y, M, i = 0;
	scanf("%lld", &T);
	for(i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &X, &Y, &M);
		printf("%lld\n", div(X, M, Y));
	}
    return 0;
}

long long int div(long long int num, long long int mod, long long int pow) {
	if(pow == 1) {
		return num%mod;
	}
	printf("at power %lld\n", pow);
	return ((num%mod)*div(num, mod, pow-1))%mod;
}

// (a1.a2.a3.....an)%n = ((a1%n).(a2%n).(a3%n).....(an%n))%n
// (a.b)%n = ((a%n).(b%n))%n
// return ((a%n)*div(p))
