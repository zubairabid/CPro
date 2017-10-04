#include <stdio.h>
char sieve[100001]; // sieve[i] stores 0 if prime, 1 if composite. Global variable => all 0 by default
char sum[100001];
int main() {
	sieve[0] = 1;
	sieve[1] = 1;
	
	int i, j, k;	
	
	for(i = 2; i <= 101; i++) {
		if(sieve[i] == 1) {
			continue;
		}
		for(j = i<<1; j < 100001; j+=i) {
			sieve[j] = 1;
		}
	}
	for(i = 0; i < 100001; i++) {
		if(sieve[i] == 0) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
