#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main() {
    int N, Q, i, j, k, l1, l2;
    int incr = 0;
    //update with algorithm later
    scanf("%d %d", &N, &Q);
    int a[N];
    int chk[N][2]; // lists the start and stop points for all 

    for(l1 = 0; l1 < N; l1++) {
        scanf("%d", &a[l1]);
        chk[l1][0] = 1<<32;
        chk[l1][1] = 1<<32;
    }

    for(l1 = 0; l1 < N; l1++) {
        scanf("%d %d %d", &i, &j, &k);
        chk[i][0] = 1; //=> update starts here
        chk[j][0] = 0; //=> update ends here
        chk[i][1] = k; //=> update is k
        chk[j][1] = k; //=> update is k
    }

    for(l1 = 0; l1 < N; l1++) {

    }

    for(l1 = 0; l1 < N; l1++) {
        printf("%d ", a[l1]);
    }
    printf("\n");

    return 0;
}

