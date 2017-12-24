#include <stdio.h>
//#include <stdlib.h>

char sieve[1000001]; // sieve[i] stores 0 if prime, 1 if composite. Global variable => all 0 by default
long long sum[1000001];

int main() {
    int i, j, T, n, m;
    
    sieve[0] = 1;
    sieve[1] = 1;
    
    i = 2, j = 2<<1;	
    for(i = 2; i <= 1001; i++) {
        if(sieve[i] == 1) {
            continue;
        }
        for(j = i<<1; j < 1000001; j+=i) {
            sieve[j] = 1;
        }
    }
    for(i = 0; i < 1000001; i++) {
        sum[i] = sum[i-1];
        if(sieve[i] == 0)
    	sum[i]+=i;
    }
    
    //for(i = 0; i < 1000001; i++) {
    //    printf("%d:%lld,%d\n", i, sum[i], sieve[i]);

    //}
    
    i=2;
    scanf("%d", &T);//Input testcase number

    for(i = 0; i < T; i++) {
        scanf("%d %d", &n, &m); //Input Bounds
        printf("%lld\n", (sum[m]-sum[n-1]));
    }
    return 0;
}
		
