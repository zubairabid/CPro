#include <stdio.h>
#include <string.h>

char* sol[12] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}; //stores the solution of (n-1) for easy access, if needed
void solset(long long int);

int main() {
	long long int i, j, k, T, N;

	scanf("%lld", &N); // n <= 10

	printf("%lld\n", N);

	return 0;
}

void solset(long long int len) {
	if(len == 1) {
		sol[len] = "() ";
		return sol[len];
	}
	if(strcmp(sol[len], " ") != 0) {
		return sol[len];	
	}
	solset(len-1);
	
}