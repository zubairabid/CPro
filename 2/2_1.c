#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main() {
    int N, K, i, j, sum, c = 0;

    scanf("%d %d", &N, &K);
    
    int a[N], comp[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for(i = 1; i < (1<<N); i++) { //loop for subsets
        sum = 0;
        //fill subset array:
        for(j = N-1; j>=0; j--) {
            comp[j] = (i>>(N-1-j))&1;
        }
        //adding
        for(j = 0; j < N; j++) {
            if(comp[j] == 1) {
                sum += a[j];
            }
        }

        /*for(j = 0; j < N; j++) {//testprint
            if(comp[j] == 1)
                printf("%d ", a[j]);
        }
        printf("\n");*/
        if(sum == K) {//printing. May want to break;
	c = 1;
            printf("YES\n");
            break;
        }
    }
    if(c==0) {
        printf("NO\n");
    }

    return 0;
}
