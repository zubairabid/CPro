#include <stdio.h>
long long int freq[20000010];

int main() {
	long long int i, sum = 0, n, t;
	scanf("%lld", &n);
	for(i = 0; i < n; i++) {
		scanf("%lld", &t);
		freq[(t+1000001)]++;
		if(freq[(t+1000001)] == 2) {
			sum++;
		}
	}
	printf("%lld\n", sum);
	return 0;
}