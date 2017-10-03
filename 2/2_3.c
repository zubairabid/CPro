#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main() {
    int N, Q, i, j, k, l1, l2;

    //update with algorithm later
    scanf("%d %d", &N, &Q);
    int a[N];

    for(l1 = 0; l1 < N; l1++) {
        scanf("%d", &a[l1]);
    }

    for (l1 = 0; l1 < Q; ++l1)
    {
        scanf("%d %d %d", &i, &j, &k);
        for(l2 = i; l2 <=j; l2++) {
            a[l2] += k;
        }
    }

    for(l1 = 0; l1 < N; l1++) {
        printf("%d ", a[l1]);
    }
    printf("\n");

    return 0;
}

