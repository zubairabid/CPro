#include <stdio.h>

//unsigned long long int t = 11111111110000000000;
unsigned long long int ar[1000000];
//int c = 0;
int track = 0;

unsigned long long int n10(int exp) {
	unsigned long long int res = 1;
	int i = 0;
	for(i = 0; i < exp; i++) {
		res*=10;
	}
	return res;
}

void convstr(unsigned long long int num, long long int len) {
	int i;
	for(i = len-1; i >= 0; i--) {
		printf("%c", (((num/n10(i))%10)==1?'(':')'));
	}
	printf("\n");
}

void generate(long long int N, int c) {
	//c tracks the initial state of the system
	if(N==0 && c==0) {
		ar[track+1] = ar[track];
		track++;
		return;
	}
	else if(N==0 && c != 0) {
		return;
	}


	if(c > 0) { // => existence of excess open brackets
		ar[track] = ar[track]*10; //+0
		generate(N-1, c-1);
		ar[track]/=10; //original state
		ar[track] = ar[track]*10 + 1;
		generate(N-1, c+1);
		ar[track]/=10;
	}

	if(c == 0) { // ==> equal no. of brackets.
		ar[track] = ar[track]*10+1;
		//c++;
		generate(N-1, c+1);
		ar[track]/=10;
		ar[track] = ar[track]*10; //+0
		generate(N-1, c-1);
		ar[track]/=10; //original state
		
	}
}

int main() {
	
	//printf("%llu\n", t);
	
	long long int i, j, k, T, N;
	 
	scanf("%lld", &N);
	
	generate(2*N, 0);

	for(i = 0; i < track; i++) {
		//printf("%llu\n", ar[i]);
		convstr(ar[i], (2*N));
	}
	//printf("%d\n", (track));

	/*
	long long int i, j, k, T, N;
	 
	scanf("%lld", &N);
	
	for(i = 0; i < N; i++) {
		
	}
	
	printf("%lld\n", N);
	*/

	return 0;
}