#include <stdio.h>

long long int arr[10000009];
long long int substatus[10000009];

int main(void) {
	long long int i, j, k, n, max = 0;
	scanf("%lld", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	
	for(i = 0; i < n; i++) {
		k = 0;
		for(j = i-1; j >= 0; j--) {
			if(arr[j] < arr[i] && substatus[j] > k) {
				k = substatus[j];
			}
		}
		k++;
		substatus[i] = k;
		//printf("%lld ", k);
		if(k > max) {
			max = k;
		}
	}
	printf("\n%lld\n", max);
	// your code goes here
	return 0;
}
