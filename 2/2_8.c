#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main() {

    int i, j, n, k, flag, c = 0;

    scanf("%d %d", &n, &k);
    int inp;
    int var[n+1], count[n+1];
    for(i = 0; i < n+1; i++) {
        flag = 0;
        scanf("%d", &inp);
        for(j = 0; j < n+1; j++) {//checks if input was there previously
            if(var[j] == inp) {//if it was, set flag and count++
                flag = 1;
                count[j]++;
            }
        }
        if(flag == 0) {//if it wasn't,
            var[c] = inp;//set var
            count[c]=1;// and flag
            c++;
        }

    }
    var[c] = count[c] = 1<<31; // setting a stop, essentially
    for(i = 0; count[i]!=1<<31; i++) {
        if(count[i] == 1)
            printf("%d\n", var[i]);
    }
    return 0;
}

