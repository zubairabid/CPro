#include <stdio.h>
#include <string.h>
long long int loc[100][2];
int filled=0;

int main() {
	long long int abx, aby, i, j, k, T, N, M, Q, x, y;
 	char eh[100]="";
	scanf("%lld %lld", &N, &M);
	scanf("%lld", &Q);

	for(i = 0; i < Q; i++) {
		scanf("%s", eh);
		scanf("%lld %lld", &x, &y);

		if(strcmp(eh, "Add") == 0) {
			loc[filled][0] = x;
			loc[filled++][1] = y;
		}
		else if(strcmp(eh, "Find") == 0) {
			if(filled == 0) {
				//-1
				printf("-1\n");
			}
			else {
				k = 20000;
				for(j = 0; j < filled; j++) {
					abx = loc[j][0] - x;
					aby = loc[j][1] - y;
					abx = abx>0?abx:-abx;
					aby = aby>0?aby:-aby;
					if(abx+aby < k) {
						k = abx+aby;
					}
				}
				printf("%lld\n", k);
			}
		}
		else {
			printf("What the fuhcs\n");
		}

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