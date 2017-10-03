#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

long double factorial(int);

int main() {
    int i, N, T;
    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("%.0llf\n", factorial(N));
    }

    return 0;
}

long double factorial(int n) {
    if(n==1 || n==0)
        return 1;
    long double f = n*(n-1);
    long double i;
    if(n%2==0) {
        for(i = 2; i < n/2; i++) {
            f *= (i*(n-i));
        }
        f *= (n/2);
    }
    else {
        for(i = 2; i <= n/2; i++) {
            f *= (i*(n-i));
        }
    }

    return f;
}

