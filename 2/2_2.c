#include <stdio.h>

long long int A[100001];
long long int fr[100001];
int main(void) {
	long int i, N, l = 0, r = 0;
	long long int sum = 0;
	
	scanf("%lld", &N); //limit input
	for(i = 0; i < N; i++) {//array input
		scanf("%lld", &A[i]);	
	}
	
	while(r < N) {
		//printf("Right pointer is at %lld (left at %lld)\n", r, l);
		fr[A[r]]++;
		//printf("%lld exists. Frequency is %lld\n", A[r], fr[A[r]]);
		if(fr[A[r]] > 1) {
			do {
				fr[A[l]]--;
				//printf("%lld now existed %lld times\n", A[l], fr[A[l]]);
				l++;
				//printf("Left pointer is now at %lld\n", l);
			} while(fr[A[r]] > 1);
			
			fr[A[r]] = 0;
			r--;
		}
		else {
			sum += ((r-l+1)*(r-l+2))/2;
		}
		r++;
	}
	
	printf("%lld\n", sum);
	return 0;
}
