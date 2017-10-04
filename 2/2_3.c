#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
int b[1000000];
int main() {
    int N, Q, i, j, k, l;
    int r = 0;
    //update with algorithm later
    scanf("%d %d", &N, &Q);
    int a[N];

    for(l = 0; l < N; l++) { // loop for array input
        scanf("%d", &a[i]);
    }

    for(l = 0; l < Q; l++) { // loop for updates
        scanf("%d %d %d", &i, &j, &k);
        b[i] += k;
        b[j+1] -= k;
    }

    for(l = 0; l < N; l++) { // loop to update and print
        r += b[l];
        a[l] += r;
        printf("%d ", a[l]);
    }
    printf("\n");

    return 0;
}

