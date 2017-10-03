#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

int prime(int);

int main() {

    int i, j, T, n, m;
    long long s = 0;
    scanf("%d", &T);//Input testcase number

    for(i = 0; i < T; i++) {
        scanf("%d %d", &m, &n); //Input Bounds
        s = 0; // reset or bust

        for (j = m; j <= n; j++) {
            if(prime(j) == 1)
                s+=j;
        }
        printf("%lld\n", s);

    }
    return 0;
}

int prime(int n) { //prime function, may need optimization
    int i;
    for(i = 2; i <= sqrt(n); i++) {
        if(n%i==0)
            return 0;
    }

    return n!=1?1:0;
}

