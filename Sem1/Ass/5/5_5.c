#include <stdio.h>

long long int arr[10000009];
long long int substatus[10000009];
long long int traceroute[10000009];

void print(long long int mloc) {
	//printf("At loc = %lld; routing to arr[%lld] = %lld\n", mloc, mloc, arr[mloc]);
	if(traceroute[mloc] == -1) {
		printf("%lld ", mloc);
		return;
	}
	print(traceroute[mloc]);
	printf("%lld ", mloc);
}

int main(void) {
	long long int i, j, k, n, max = 0, mloc = 0; 
	scanf("%lld", &n); // number of inputs
	
	for(i = 0; i < n; i++) {
		scanf("%lld", &arr[i]); // input into the array
	}
	
	for(i = 0; i < n; i++) { // iteration through the array
		traceroute[i] = -1;
		k = 0;
		for(j = i-1; j >= 0; j--) { // checks for LIS number
			if(arr[j] < arr[i] && substatus[j] > k) {
				k = substatus[j];
				if(k == 0) {
					traceroute[i] = -1;
				}
				else {
					traceroute[i] = j;
				}
			}
		}
		k++;
		substatus[i] = k;
		//printf("%lld ", k);
		if(k >= max) {
			max = k;
			mloc = i;
		}
	}
	printf("%lld\n", max);

	//for(i = 0; i < n; i++) {
	//	printf("%lld - %lld \n", substatus[i], traceroute[i]);
	//}
	//printf("\n");
	print(mloc);
	printf("\n");
	// your code goes here
	return 0;
}