#include <stdio.h>
#include <string.h>
int main() {
	int i, j, k, T, N;

	//scanf("%lld", &N);

	//for(i = 0; i < N; i++) {
	//	
	//}

	//printf("%lld\n", N);

	char* testtext = "1 2 334 455";
	char* temp;
	for(i = 0; i < 4; i++) {
		T = fscanf(testtext, "%s", temp);
		printf("%d %s\n", T, temp);
	}

	return 0;
}