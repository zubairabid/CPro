#include <stdio.h>

int A[100001];
int fr[100001];
int main(void) {
	int i, N, l = 0, r = 0;
	long long int sum = 0;
	
	scanf("%d", &N); //limit input
	for(i = 0; i < N; i++) {//array input
		scanf("%d", &A[i]);	
	}
	
	while(r < N) {
		//printf("Right pointer is at %d (left at %d)\n", r, l);
		fr[A[r]]++;
		//printf("%d exists. Frequency is %d\n", A[r], fr[A[r]]);
		if(fr[A[r]] > 1) {
			do {
				fr[A[l]]--;
				//printf("%d now existed %d times\n", A[l], fr[A[l]]);
				l++;
				//printf("Left pointer is now at %d\n", l);
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
