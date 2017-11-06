#include <stdio.h>

//unsigned long long int t = 11111111110000000000;
unsigned long long int ar[1000000];
int c = 0;
int track = 0;

int generate(long long int N) {
	if(N==0 && c==0) {
		//ar[track] = ar[track]*10 + 0;
		printf("Reset\n");
		track++;
		ar[track] = ar[track-1];
		ar[track] /= 10;
		c = -1;
		return 1;
	}
	else if (N==0 && c!=0) {
		//c=0;
		ar[track]/=10;
		return 0 ;
	}

	printf("N: %lld c:%d (-N/2):%lld\n", N, c, ((N/2)*-1));

	if(c < 0) {
		ar[track] = ar[track]*10 + 0;
		//track++;
		c++;
		printf("Closing bracket\t\t%llu\n", ar[track]);
		if(generate(N-1) == 0) {
			c--;
			c--;
			ar[track] /= 10;
		}
	}
	if (c >= ((N/2))*-1){
		ar[track] = ar[track]*10 + 1;
		//track++;
		c--;
		printf("Opening bracket\t\t%llu\n", ar[track]);
		if(generate(N-1) == 0) {
			c++;
			c++;
			ar[track] /= 10;
		}
	}
	ar[track] /= 10;
}

int main() {
	
	//printf("%llu\n", t);
	
	long long int i, j, k, T, N;
	 
	scanf("%lld", &N);
	
	generate(2*N);

	for(i = 0; i < track+1; i++) {
		printf("%llu\n", ar[i]);
	}

	/*
	long long int i, j, k, T, N;
	 
	scanf("%lld", &N);
	
	for(i = 0; i < N; i++) {
		
	}
	
	printf("%lld\n", N);
	*/

	return 0;
}