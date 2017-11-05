#include <stdio.h>
#include <string.h>
int dot[100][100];
int map[100][100];
int dists[50][2];
int c = 0;

int find(int, int);

int main() {
	
	int i, j, k, T, N, M, Q, x, y, t1, t2;
 	char eh[10] = " ";
	scanf("%d %d", &N, &M);

	scanf("%d", &Q);

	for( i = 0; i < Q; i++ ) {
		//eh="Find";
		scanf("%s", eh);
		scanf("%d %d", &x, &y);
		//correction for 1 indexing:
		x--;
		y--;
		if(strcmp(eh, "Find") == 0) {
			printf("Entered Find zone\n");
			map[x][y] = find(x, y);

			for(t1 = 0; t1 < N; t1++) {
				for(t2 = 0; t2 < M; t2++)
					printf("%d", dot[t1][t2]);
				printf("\n");
			}
			printf("\n");

			printf("Answer: %d\n", map[x][y]);
		}
		else if(strcmp(eh, "Add") == 0) {
			printf("Entered Addition zone\n");
			dot[x][y] = 1;
			dists[c++][0] = x;
			dists[c][1] = y;

			for(t1 = 0; t1 < N; t1++) {
				for(t2 = 0; t2 < M; t2++)
					printf("%d", dot[t1][t2]);
				printf("\n");
			}
			printf("\n");

			for(t1 = 0; t1 < c; t1++) {
				printf("%d %d\n", dists[c][0], dists[c][1]);
			}
			printf("\n");
		}
		else
			printf("what the fuck\n");
	}

/////////////////////THIS CODE IDS WERONG
	/*
	long long int i, j, k, T, N;
 
	scanf("%lld", &N);

	for(i = 0; i < N; i++) {
		
	}

	printf("%lld\n", N);
	*/

	return 0;
}

int find(int x, int y) {
	//printf("Entered find function\n");
	int abx, aby;
	int max = 200;
	int i;
	for(i = 0; i < c; i++) {
		//printf("Entered find loop for i = %d\n", i);
		abx = x-dists[i][0];
		aby = y-dists[i][1];
		abx = abx<0?-abx:abx;
		aby = aby<0?-aby:aby;
		if(abx+aby < max) {
			max = aby;
		}
	}
	//map[x][y] = max==200?-1:max;
	return max==200?-1:max;
}