#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main() {
    int T, M, X, Y, i, j, p;
    scanf("%d", &T);

    for(i = 0; i < T; i++) {
        scanf("%d %d %d", &X, &Y, &M);
        p = 1;
        for (j = 0; j < Y; ++j)
        {
            p = p * (X%M);
        }
        p = p%M;

        printf("%d ", p);
    }
    printf("\n");
    return 0;
}

