#include <stdio.h>
#include <string.h>
int dot[100][100];
int map[100][100];
int dists[50][2];;
int c = 0;
int find(int, int);

int main() {
	
	int i, j, k, T, N, M, Q, x, y;
 	char* eh;
	scanf("%d %d", &N, &M);

	scanf("%d", &Q);

	for( i = 0; i < Q; i++ ) {
		scanf("%s %d %d", eh, &x, &y);
		if(strcmp(eh, "Find") == 0) {
			if(dot[x][y] == 0 && map[x][y] == 0) {
				map[x][y] = find(x, y);
			}
			printf("%d\n", map[x][y]);
		}
		else if(strcmp(eh, "Add") == 0) {
			dot[x][y] = 1;
			dists[c++][0] = x;
			dists[c][1] = y;
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
	int max = 200;
	int i;
	for(i = 0; i < c; i++) {
		abx = x-dists[i][0];
		aby = y-dists[i][1];
		abx = abx<0?-abx:abx;
		aby = aby<0?-aby:aby;
		if(abx+aby < max) {
			max = aby;
		}
	}

}