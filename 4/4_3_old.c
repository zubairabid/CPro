#include <stdio.h>
char brackets[23];
unsigned long long int stores[1000000]; // stores all combos for any moment
unsigned long long int temp[1000000];
unsigned long long int cstores = 0, ctemp = 0;
char* conv(unsigned long long int, unsigned long long int);

void compute(unsigned long long int);
unsigned long long int n10(unsigned long long int); // computes 10^(2n-1)
unsigned long long int n10p(unsigned long long int); // computes 10^n

int main() {
	unsigned long long int i, j, k, T, N; // we'll be using N, 
 	
	scanf("%llu", &N);
	
	compute(N);
	for(i = 0; i < cstores; i++) {
		//printf("%llu\n", stores[i]);
		//for(j = 2*N-1; j < 100000; j-- ) {
			//printf("%llu %llu %c", stores[i], (stores[i]<<1), ((stores[i]>>j)==1?'(':')'));
		//	printf("%c", (((stores[i]/n10p(j))%10)==1?'(':')'));
		//}
		//printf("\n");
		printf("%s\n", conv(stores[i], N));
	}
	printf("%llu\n", cstores);

	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/

	return 0;
}

char* conv(unsigned long long int dex, unsigned long long int N) {
	//printf("N is %llu\n", N);
	unsigned long long int i = 2*N-1;
	//printf("i is %llu\n", i);
	
	while(i <= 10000000) {
		brackets[i--] = ((dex%10==0)?')':'(');
		dex/=10;
		//printf("brackets[%llu] = %llu\n", (i+1), brackets[i]);
	}
	brackets[2*N] = '\0';
	return brackets;

}

void compute(unsigned long long int N) {
	unsigned long long int i; 
	if(N==1) {
		stores[0] = 10;
		cstores = 1;
		return;
	}
	compute(N-1);
	for(i = 0; i < cstores; i++) {
		temp[ctemp++] = n10(N) + (10*stores[i]); // + 0;
	}
	for(i = 0; i < cstores; i++) {
		temp[ctemp++] = 100 * stores[i] + 10;

		if(temp[ctemp-1] == temp[ctemp-2]) {
			temp[ctemp-1] = 0;
			ctemp--;
		}

		temp[ctemp++] = n10(N) + (stores[i]);
		if(temp[ctemp-1] == temp[ctemp-2]) {
			temp[ctemp-1] = 0;
			ctemp--;
		}
	}
	cstores = ctemp;
	ctemp = 0;
	for(i = 0; i < cstores; i++) {
		stores[i] = temp[i];
	}
}

unsigned long long int n10(unsigned long long int N) {
	unsigned long long int result = 1, i;
	for(i = 0; i < 2*N-1; i++)
		result *= 10;
	return result;
}

unsigned long long int n10p(unsigned long long int N) {
	unsigned long long int result = 1, i;
	for(i = 0; i < N; i++)
		result *= 10;
	return result;
}